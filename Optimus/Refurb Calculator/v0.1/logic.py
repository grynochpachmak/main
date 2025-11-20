import json, re
from typing import Optional, Dict, Tuple
from config import RULES, HUMAN_NAMES, round_up_to_5, CalcStep, VAT, PROFIT

def escape_md2(text: str) -> str:
    esc = r"_*[]()~`>#+-=|{}.!\\"
    s = str(text)
    return "".join("\\" + c if c in esc else c for c in s)

with open("data/shortcuts.json", "r", encoding="utf-8") as f:
    SHORTCUTS: Dict[str, list[str]] = json.load(f)

CATEGORY_WORDS = {
    "smartphone": ["smartphone", "phone", "sm", "sp"],
    "iphone":     ["iphone", "iph", "ios"],
    "tablet":     ["tablet", "tab"],
    "laptop":     ["laptop", "notebook", "nb", "lap"],
    "pc":         ["pc", "desktop", "computer"],
}

ITEM_WORDS = {
    "display": ["display", "disp", "lcd", "screen"],
    "display_touch": ["touch", "tpanel", "tp"],
    "battery": ["battery", "bat", "accu"],
    "keyboard": ["keyboard", "kb", "keyb"],
    "fan_office": ["fan", "cooler", "vent"],
    "fan_gaming": ["fang", "coolerg"],
    "fan_liquid": ["fanl", "liquid"],
    "case": ["case", "cover", "housing", "chassis"],
}

def normalize_spaces(s: str) -> str:
    return re.sub(r"\s+", " ", s.lower()).strip()

def tokenize(s: str) -> list[str]:
    s = normalize_spaces(s)
    raw = re.findall(r"[a-z0-9]+", s)
    return raw

def extract_price(text: str) -> Optional[float]:
    nums = [float(x.replace(",", ".")) for x in re.findall(r"\d+(?:[.,]\d+)?", text)]
    return max(nums) if nums else None

def match_shortcut(tokens: list[str], nospace: str) -> Optional[str]:
    for t in tokens:
        if t in SHORTCUTS:
            return t
        
    for sc in sorted(SHORTCUTS.keys(), key=len, reverse=True):
        if nospace.endswith(sc) and nospace[:-len(sc)].isdigit():
            return sc
        if nospace.startswith(sc) and nospace[len(sc):].isdigit():
            return sc
    return None

def detect_by_words(tokens: list[str]) -> Tuple[Optional[str], Optional[str]]:
    cat = None
    for c, words in CATEGORY_WORDS.items():
        if any(w in tokens for w in words):
            cat = c
            break

    item = None
    if any(w in tokens for w in ITEM_WORDS["display_touch"]):
        item = "display_touch"
    else:
        for k, words in ITEM_WORDS.items():
            if k == "display_touch":
                continue
            if any(w in tokens for w in words):
                item = k
                break
    return cat, item

def smart_iphone_tablet_display_percent(price: float) -> int:
    if price <= 1200: return 40
    if price <= 1500: return 30
    return 15

def calc_from_rules(price: float, cat: str, item: str) -> CalcStep:
    base = int(price)

    if cat == "general":
        with_vat = price * (1 + VAT)
        with_profit = with_vat * (1 + PROFIT)
        refurb = round_up_to_5(with_profit)
        return CalcStep(
            key_human=HUMAN_NAMES[(cat, item)],
            purchase_price=base,
            refurb_str=f"{base} + VAT 20% = {round_up_to_5(with_vat)} MDL + Profit 10% → {refurb} MDL",
            refurb_price=refurb,
            mount_str=None,
            final_price=refurb
        )

    if cat == "extern":
        pct = RULES["extern"]["percent"]
        refurb = round_up_to_5(price * (1 + pct/100))
        final = refurb
        return CalcStep(
            key_human=HUMAN_NAMES[(cat, item)],
            purchase_price=base,
            refurb_str=f"{base} + {pct}% = {refurb} MDL",
            refurb_price=refurb,
            mount_str=f"{refurb} + 0 = {final} MDL",
            final_price=final
        )

    if cat in ("smartphone", "iphone", "tablet"):
        if item == "display" or item == "display_touch":
            pct = smart_iphone_tablet_display_percent(price)
            tiers = RULES[cat]["display"]
            mount = (tiers[0]["mount"] if pct == 40 else
                     tiers[1]["mount"] if pct == 30 else
                     tiers[2]["mount"])
            refurb = round_up_to_5(price * (1 + pct/100))
            final = refurb + mount
            key_tuple = (cat, "display")
            return CalcStep(
                key_human=HUMAN_NAMES[key_tuple],
                purchase_price=base,
                refurb_str=f"{base} + {pct}% = {refurb} MDL",
                refurb_price=refurb,
                mount_str=f"{refurb} + {mount} = {final} MDL",
                final_price=final
            )
        rule = RULES[cat].get(item, RULES[cat]["other"])
        pct, mount = rule["percent"], rule["mount"]
        refurb = round_up_to_5(price * (1 + pct/100))
        final = refurb + mount
        return CalcStep(
            key_human=HUMAN_NAMES[(cat, item)],
            purchase_price=base,
            refurb_str=f"{base} + {pct}% = {refurb} MDL",
            refurb_price=refurb,
            mount_str=f"{refurb} + {mount} = {final} MDL" if mount else f"{refurb} + 0 = {refurb} MDL",
            final_price=final
        )

    if cat in ("laptop", "pc"):
        if item in ("display", "display_touch"):
            r = RULES[cat]["display"]
            pct = r["percent"]
            mount = r["mount_touch"] if item == "display_touch" else r["mount"]
            refurb = round_up_to_5(price * (1 + pct/100))
            final = refurb + mount
            return CalcStep(
                key_human=HUMAN_NAMES[(cat, item)],
                purchase_price=base,
                refurb_str=f"{base} + {pct}% = {refurb} MDL",
                refurb_price=refurb,
                mount_str=f"{refurb} + {mount} = {final} MDL",
                final_price=final
            )
        if item and item.startswith("fan_"):
            r = RULES[cat]["fan"]
            pct = r["percent"]
            mode = item.split("_", 1)[1]
            mount = r["mounts"][mode]
            refurb = round_up_to_5(price * (1 + pct/100))
            final = refurb + mount
            return CalcStep(
                key_human=HUMAN_NAMES[(cat, item)],
                purchase_price=base,
                refurb_str=f"{base} + {pct}% = {refurb} MDL",
                refurb_price=refurb,
                mount_str=f"{refurb} + {mount} = {final} MDL",
                final_price=final
            )
        r = RULES[cat][item]
        pct, mount = r["percent"], r["mount"]
        refurb = round_up_to_5(price * (1 + pct/100))
        final = refurb + mount
        return CalcStep(
            key_human=HUMAN_NAMES[(cat, item)],
            purchase_price=base,
            refurb_str=f"{base} + {pct}% = {refurb} MDL",
            refurb_price=refurb,
            mount_str=f"{refurb} + {mount} = {final} MDL",
            final_price=final
        )

    with_vat = price * (1 + VAT)
    with_profit = with_vat * (1 + PROFIT)
    refurb = round_up_to_5(with_profit)
    return CalcStep(
        key_human=HUMAN_NAMES[("general","general")],
        purchase_price=base,
        refurb_str=f"{base} + VAT 20% = {round_up_to_5(with_vat)} MDL + Profit 10% → {refurb} MDL",
        refurb_price=refurb,
        mount_str=None,
        final_price=refurb
    )

def process_message(raw_text: str) -> str:
    text = normalize_spaces(raw_text)
    tokens = tokenize(text)
    nospace = "".join(tokens)

    price = extract_price(text)
    if price is None:
        return "Price not found\\. Example: `2560 ds`"

    sc = match_shortcut(tokens, nospace)

    cat = item = None
    if sc:
        cat, item = SHORTCUTS[sc][0], SHORTCUTS[sc][1]
    else:
        cat, item = detect_by_words(tokens)
        if item and not cat:
            cat = "smartphone"
        if not cat:
            cat, item = "general", "general"

    step = calc_from_rules(price, cat, item)

    key_h = escape_md2(step.key_human)
    purchase = escape_md2(step.purchase_price)
    refurb_s = escape_md2(step.refurb_str)
    mount_s = escape_md2(step.mount_str) if step.mount_str else None
    final_s = escape_md2(step.final_price)

    lines = [
        f"`Key:` {key_h}",
        f"`Purchase Price:` {purchase} MDL",
        f"`Refurb Price:` {refurb_s}",
    ]
    if mount_s:
        lines.append(f"`Mount:` {mount_s}")
    lines.append(f"`Final Price:` {final_s} MDL")
    return "\n".join(lines)

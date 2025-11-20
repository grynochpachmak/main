import re
from typing import Optional, Iterable, Tuple, List, Dict, Any
from config import Cfg

# --- regex ---
_RX_WS  = re.compile(r"\s+")
_RX_TOK = re.compile(r"[a-z0-9]+")
_RX_WORD= re.compile(r"[a-z]+")
_RX_NUM = re.compile(r"\d+(?:[.,]\d+)?")

def normalize(s: str) -> str:
    return _RX_WS.sub(" ", s.lower().strip())

def tokenize(s: str) -> list[str]:
    return _RX_TOK.findall(normalize(s))

def extract_words(s: str) -> list[str]:
    return _RX_WORD.findall(normalize(s))

def extract_price(text: str) -> Optional[float]:
    nums = [float(x.replace(",", ".")) for x in _RX_NUM.findall(text)]
    return max(nums) if nums else None

def detect_shortcut(text: str) -> Optional[Tuple[str, str]]:
    toks = tokenize(text)
    nospace = "".join(toks)
    sc_keys = sorted(Cfg.SHORTCUTS.keys(), key=len, reverse=True)
    for t in toks:
        if t in Cfg.SHORTCUTS:
            return Cfg.SHORTCUTS[t][0], Cfg.SHORTCUTS[t][1]
    for sc in sc_keys:
        if nospace.endswith(sc) and nospace[:-len(sc)].isdigit():
            return Cfg.SHORTCUTS[sc][0], Cfg.SHORTCUTS[sc][1]
    for sc in sc_keys:
        if nospace.startswith(sc) and nospace[len(sc):].isdigit():
            return Cfg.SHORTCUTS[sc][0], Cfg.SHORTCUTS[sc][1]
    return None

# --- fuzzy helpers ---
def _levenshtein(a: str, b: str) -> int:
    if a == b: return 0
    if not a:  return len(b)
    if not b:  return len(a)
    prev = list(range(len(b) + 1))
    for i, ca in enumerate(a, 1):
        cur = [i]
        for j, cb in enumerate(b, 1):
            cost = 0 if ca == cb else 1
            cur.append(min(prev[j] + 1, cur[j-1] + 1, prev[j-1] + cost))
        prev = cur
    return prev[-1]

def _similarity(a: str, b: str) -> float:
    m = max(len(a), len(b))
    if m == 0: return 1.0
    return 1.0 - (_levenshtein(a, b) / m)

def _rank_fuzzy(word: str, vocab: Iterable[str]) -> List[Tuple[str, float]]:
    w = word.lower()
    scores = [(ref, _similarity(w, ref.lower())) for ref in vocab]
    scores.sort(key=lambda t: t[1], reverse=True)
    return scores

def _apply_synonyms(words: List[str], kind: str) -> List[str]:
    syn = Cfg.SYNONYMS.get(kind, {})
    return [syn.get(w, w) for w in words]

def _detect_exact_or_fuzzy(text: str, vocab: list[str], kind: str,
                           threshold: float = Cfg.THRESHOLD, margin: float = Cfg.MARGIN) -> Optional[str]:
    words = _apply_synonyms(extract_words(text), kind)

    exact_unique = sorted(set(w for w in words if w in vocab))
    if len(exact_unique) > 1:
        raise ValueError(f"Error: multiple {kind}s found: {', '.join(exact_unique)}")
    if len(exact_unique) == 1:
        return exact_unique[0]

    best_ref: Optional[str] = None
    best_s1: float = 0.0
    best_s2: float = 0.0
    for w in words:
        if len(w) == 1 and w not in vocab:
            continue
        ranked = _rank_fuzzy(w, vocab)
        if not ranked:
            continue
        ref, s1 = ranked[0]
        s2 = ranked[1][1] if len(ranked) > 1 else 0.0
        if s1 > best_s1:
            best_s1, best_s2, best_ref = s1, s2, ref

    if best_ref is None:
        return None
    if best_s1 >= threshold and (best_s1 - best_s2) >= margin:
        return best_ref
    return None

def detect_cat(text: str) -> Optional[str]:
    return _detect_exact_or_fuzzy(text, Cfg.WORDS["category"], "category")

def detect_item(text: str) -> Optional[str]:
    return _detect_exact_or_fuzzy(text, Cfg.WORDS["item"], "item")

def allowed_items_for_category(cat: str) -> List[str]:
    if cat in ("smartphone", "iphone", "tablet"):
        return ["display", "battery", "case"]
    if cat == "laptop":
        return ["display", "battery", "keyboard", "fan", "case"]
    if cat == "general":
        return ["general"]
    if cat == "extern":
        return ["extern"]
    return []

def allowed_categories_for_item(item: str) -> List[str]:
    if item == "display":
        return ["smartphone", "iphone", "tablet", "laptop"]
    if item == "battery":
        return ["smartphone", "iphone", "tablet", "laptop"]
    if item in ("keyboard", "fan"):
        return ["laptop"]
    if item == "case":
        return ["smartphone", "iphone", "laptop"]
    return []

def parse_int_choice(s: str, n: int) -> Optional[int]:
    m = re.search(r"\b([1-9][0-9]?)\b", s)
    if not m: return None
    k = int(m.group(1))
    return k-1 if 1 <= k <= n else None

# ======== CALCULUS ========

def needs_mount_input(category: str, item: str) -> bool:
    return bool(Cfg.CALC_RULES.get(category, {}).get("ask_mount", False))

def _pick_display_tier(category: str, price: float) -> Optional[Tuple[float, float]]:
    cat_rules = Cfg.CALC_RULES.get(category, {})
    tiers = cat_rules.get("display_tiers")
    if not tiers:
        return None
    for lo, hi, pct, mount in tiers:
        if lo <= price < hi:
            return pct, mount
    return None

def _calc_from_rule(price: float, rule: dict) -> Tuple[float, str]:
    pct = float(rule.get("pct", 0.0))
    mount = float(rule.get("mount", 0.0))
    part = price * (1.0 + pct) if pct > 0 else price
    total = part + mount
    breakdown = f"Base {price:.2f} + {int(pct*100)}% = {part:.2f}; Mount {mount:.0f} → Total {total:.2f}"
    return total, breakdown

def _calc_category_item(price: float, category: str, item: str) -> Tuple[float, str]:
    if item == "display":
        tier = _pick_display_tier(category, price)
        if tier is not None:
            pct, mount = tier
            part = price * (1 + pct)
            total = part + mount
            breakdown = f"Base {price:.2f} + {int(pct*100)}% = {part:.2f}; Mount {mount:.0f} → Total {total:.2f}"
            return total, breakdown
    rule = Cfg.CALC_RULES.get(category, {}).get(item)
    if isinstance(rule, dict):
        return _calc_from_rule(price, rule)
    return price, f"No rule for {category}/{item}. Total {price:.2f}"

def _calc_general(price: float, mount: float) -> Tuple[float, str]:
    rules = Cfg.CALC_RULES["general"]
    vat = float(rules["vat"])
    profit = float(rules["profit"])
    with_vat = price * (1.0 + vat)
    with_profit = with_vat * (1.0 + profit)
    total = with_profit + mount
    breakdown = f"Base {price:.2f} → +VAT {int(vat*100)}% {with_vat:.2f} → +Profit {int(profit*100)}% {with_profit:.2f}; Mount {mount:.2f} → Total {total:.2f}"
    return total, breakdown

def _calc_extern(price: float, mount: float) -> Tuple[float, str]:
    rules = Cfg.CALC_RULES["extern"]
    mult = float(rules["mult"])
    doubled = price * mult
    total = doubled + mount
    breakdown = f"Base {price:.2f} ×{mult:g} = {doubled:.2f}; Mount {mount:.2f} → Total {total:.2f}"
    return total, breakdown

def do_calculation(price: float, category: str, item: str, mount: Optional[float] = None) -> str:
    if category == "general":
        if mount is None:
            return "🧮 Please provide Mount for General."
        total, breakdown = _calc_general(price, mount)
        return f"✅ {price:.2f} → category='{category}', item='{item}'\n{breakdown}"
    if category == "extern":
        if mount is None:
            return "🧮 Please provide Mount for External."
        total, breakdown = _calc_extern(price, mount)
        return f"✅ {price:.2f} → category='{category}', item='{item}'\n{breakdown}"
    total, breakdown = _calc_category_item(price, category, item)
    return f"✅ {price:.2f} → category='{category}', item='{item}'\n{breakdown}"

# ======== INTENT PARSER ========

def interpret(text: str) -> Tuple[str, Dict[str, Any]]:
    price = extract_price(text)
    if price is None:
        return ("error", {"prompt": "❗ Price not found. Example: 2560 ds"})

    sc = detect_shortcut(text)
    if sc:
        cat, item = sc
        if item in allowed_items_for_category(cat):
            if needs_mount_input(cat, item):
                return ("ask_mount", {"price": price, "category": cat, "item": item,
                                      "prompt": f"🔧 Enter Mount for {cat}/{item}:"})
            return ("calculate", {"price": price, "category": cat, "item": item})
        opts = allowed_items_for_category(cat) or Cfg.WORDS["item"]
        prompt = "👉 Select item for {cat}: " + ", ".join(f"{i+1}) {op}" for i, op in enumerate(opts))
        return ("ask_item", {"price": price, "category": cat, "options": opts, "prompt": prompt})

    cat = detect_cat(text)
    item = detect_item(text)

    if cat is None and item is None:
        return ("ask_mount", {
            "price": price, "category": "general", "item": "general",
            "prompt": "ℹ️ No category or item detected. Applied General. 🔧 Enter Mount:"
        })

    if cat and item is None:
        options = allowed_items_for_category(cat) or Cfg.WORDS["item"]
        prompt = "👉 Select item for {cat}: " + ", ".join(f"{i+1}) {op}" for i, op in enumerate(options))
        return ("ask_item", {"price": price, "category": cat, "options": options, "prompt": prompt})

    if item and cat is None:
        options = allowed_categories_for_item(item) or [c for c in Cfg.WORDS["category"] if c not in ("general", "extern")]
        prompt = f"👉 {item.capitalize()} detected. Which category? " + ", ".join(f"{i+1}) {op}" for i, op in enumerate(options))
        return ("ask_category", {"price": price, "item": item, "options": options, "prompt": prompt})

    if cat and item:
        if item in allowed_items_for_category(cat):
            if needs_mount_input(cat, item):
                return ("ask_mount", {"price": price, "category": cat, "item": item,
                                      "prompt": f"🔧 Enter Mount for {cat}/{item}:"})
            return ("calculate", {"price": price, "category": cat, "item": item})

        options = allowed_items_for_category(cat)
        if options:
            prompt = f"⚠️ '{item}' is not valid for {cat}. Select item: " + ", ".join(f"{i+1}) {op}" for i, op in enumerate(options))
            return ("ask_item", {"price": price, "category": cat, "options": options, "prompt": prompt})

        options = allowed_categories_for_item(item) or [c for c in Cfg.WORDS["category"] if c not in ("general", "extern")]
        prompt = f"⚠️ {item.capitalize()} incompatible. Which category? " + ", ".join(f"{i+1}) {op}" for i, op in enumerate(options))
        return ("ask_category", {"price": price, "item": item, "options": options, "prompt": prompt})

    return ("ask_mount", {
        "price": price, "category": "general", "item": "general",
        "prompt": "🤷 Could not confidently detect. Applied General. 🔧 Enter Mount:"
    })

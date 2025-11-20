# config.py
import math
from dataclasses import dataclass
from typing import Optional, Literal

Currency = Literal["MDL"]

VAT = 0.20
PROFIT = 0.10

def round_up_to_5(x: float) -> int:
    return int(math.ceil(x / 5.0) * 5)

@dataclass
class CalcStep:
    key_human: str
    purchase_price: int
    refurb_str: str
    refurb_price: int
    mount_str: Optional[str]
    final_price: int
    currency: Currency = "MDL"

RULES = {
    "smartphone": {
        "display": [
            {"limit": 1200, "percent": 40, "mount": 350},
            {"limit": 1500, "percent": 30, "mount": 350},
            {"limit": None, "percent": 15, "mount": 350},
        ],
        "battery": {"percent": 45, "mount": 150},
        "cover":   {"percent": 45, "mount": 0},
        "other":   {"percent": 45, "mount": 0},
    },
    "iphone": {
        "display": [
            {"limit": 1200, "percent": 40, "mount": 450},
            {"limit": 1500, "percent": 30, "mount": 450},
            {"limit": None, "percent": 15, "mount": 450},
        ],
        "battery": {"percent": 45, "mount": 450},
        "cover":   {"percent": 45, "mount": 0},
        "other":   {"percent": 45, "mount": 0},
    },
    "tablet": {
        "display": [
            {"limit": 1200, "percent": 40, "mount": 350},
            {"limit": 1500, "percent": 30, "mount": 350},
            {"limit": None, "percent": 15, "mount": 350},
        ],
        "battery": {"percent": 45, "mount": 150},
        "cover":   {"percent": 45, "mount": 0},
        "other":   {"percent": 45, "mount": 0},
    },
    "laptop": {
        "display": {"percent": 60, "mount": 350, "mount_touch": 650},
        "case":    {"percent": 50, "mount": 450},
        "fan":     {"percent": 70, "mounts": {"office": 250, "gaming": 350, "liquid": 650}},
        "keyboard":{"percent": 70, "mount": 450},
        "battery": {"percent": 40, "mount": 270},
    },
    "pc": {
        "display": {"percent": 60, "mount": 350, "mount_touch": 650},
        "case":    {"percent": 50, "mount": 450},
        "fan":     {"percent": 70, "mounts": {"office": 250, "gaming": 350, "liquid": 650}},
        "battery": {"percent": 40, "mount": 270},
        "keyboard":{"percent": 70, "mount": 450},
    },
    "extern": {"percent": 100, "mount": 0},
    "general": {"formula": "vat_then_profit"}
}

HUMAN_NAMES = {
    ("smartphone","display"): "Smartphone Display",
    ("smartphone","battery"): "Smartphone Battery",
    ("smartphone","cover"):   "Smartphone Cover",
    ("iphone","display"):     "iPhone Display",
    ("iphone","battery"):     "iPhone Battery",
    ("iphone","cover"):       "iPhone Cover",
    ("tablet","display"):     "Tablet Display",
    ("tablet","battery"):     "Tablet Battery",
    ("tablet","cover"):       "Tablet Cover",
    ("laptop","display"):     "Laptop Display",
    ("laptop","display_touch"): "Laptop Display (Touch)",
    ("laptop","battery"):     "Laptop Battery",
    ("laptop","keyboard"):    "Laptop Keyboard",
    ("laptop","fan_office"):  "Laptop Fan (Office)",
    ("laptop","fan_gaming"):  "Laptop Fan (Gaming)",
    ("laptop","fan_liquid"):  "Laptop Fan (Liquid Metal)",
    ("laptop","case"):        "Laptop Case",
    ("pc","display"):         "PC Display",
    ("pc","display_touch"):   "PC Display (Touch)",
    ("pc","battery"):         "PC Battery",
    ("pc","keyboard"):        "PC Keyboard",
    ("pc","fan_office"):      "PC Fan (Office)",
    ("pc","fan_gaming"):      "PC Fan (Gaming)",
    ("pc","fan_liquid"):      "PC Fan (Liquid Metal)",
    ("pc","case"):            "PC Case",
    ("extern","extern"):      "Extern (Import)",
    ("general","general"):    "General"
}

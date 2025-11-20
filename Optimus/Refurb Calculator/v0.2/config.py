import os
from dataclasses import dataclass
from dotenv import load_dotenv

# Load .env at import time
load_dotenv()

# === RUNTIME ===
BOT_TOKEN = ("8343939504:AAEKsaIs3tGrxXe8DZ3CfCB5zDgw_zt8sNo")  # TODO: SET BY .ENV

# === FUZZY TUNING ===
THRESHOLD: float = 0.80
MARGIN: float = 0.05

# === VOCAB ===
WORDS = {
    "category": ["smartphone", "iphone", "tablet", "laptop", "general", "extern"],
    "item": ["display", "battery", "case", "fan", "keyboard"],
}

# === SYNONYMS ===
SYNONYMS = {
    "category": {
        "phone": "smartphone", "smart": "smartphone", "android": "smartphone", "smartphone": "smartphone",
        "ios": "iphone", "iphone": "iphone",
        "ipad": "tablet", "tab": "tablet", "tabletpc": "tablet", "tablet": "tablet",
        "notebook": "laptop", "nb": "laptop", "ultrabook": "laptop", "laptop": "laptop",
        "gen": "general", "common": "general", "general": "general",
        "external": "extern", "outside": "extern", "outer": "extern", "ext": "extern", "extern": "extern",
    },
    "item": {
        "screen": "display", "lcd": "display", "oled": "display", "glass": "display", "display": "display",
        "accu": "battery", "accum": "battery", "akku": "battery", "accumulator": "battery", "batt": "battery", "battery": "battery",
        "kb": "keyboard", "keyb": "keyboard", "keyboard": "keyboard",
        "cooler": "fan", "vent": "fan", "fan": "fan",
        "housing": "case", "cover": "case", "shell": "case", "carcass": "case", "case": "case",
    },
}

# === SHORTCUTS ===
SHORTCUTS = {
    "ds": ["smartphone", "display"],
    "bs": ["smartphone", "battery"],
    "di": ["iphone", "display"],
    "bi": ["iphone", "battery"],
    "dt": ["tablet", "display"],
    "bt": ["tablet", "battery"],
    "dl": ["laptop", "display"],
    "bl": ["laptop", "battery"],
    "kl": ["laptop", "keyboard"],
    "g":  ["general", "general"],
    "e":  ["extern", "extern"],
}

# === CALCULUS RULES ===
CALC_RULES = {
    "smartphone": {
        "display_tiers": [
            (0, 1200, 0.40, 350.0),
            (1200, 1500, 0.30, 350.0),
            (1500, float("inf"), 0.15, 350.0),
        ],
        "battery": {"pct": 0.45, "mount": 250.0},
        "case":    {"pct": 0.00, "mount": 350.0},
    },
    "tablet": {
        "display_tiers": [
            (0, 1200, 0.40, 350.0),
            (1200, 1500, 0.30, 350.0),
            (1500, float("inf"), 0.15, 350.0),
        ],
        "battery": {"pct": 0.45, "mount": 250.0},
        "case":    {"pct": 0.00, "mount": 350.0},
    },
    "iphone": {
        "display_tiers": [
            (0, 1200, 0.40, 450.0),
            (1200, 1500, 0.30, 450.0),
            (1500, float("inf"), 0.15, 450.0),
        ],
        "battery": {"pct": 0.45, "mount": 350.0},
        "case":    {"pct": 0.00, "mount": 450.0},
    },
    "laptop": {
        "display":  {"pct": 0.60, "mount": 350.0},
        "case":     {"pct": 0.50, "mount": 450.0},
        "fan":      {"pct": 0.70, "mount": 270.0},
        "keyboard": {"pct": 0.70, "mount": 450.0},
        "battery":  {"pct": 0.40, "mount": 270.0},
    },
    "general": {"vat": 0.20, "profit": 0.10, "ask_mount": True},
    "extern":  {"mult": 2.0, "ask_mount": True},
}

# Handy import bundle
class Cfg:
    THRESHOLD: float = THRESHOLD
    MARGIN: float = MARGIN
    WORDS: dict = WORDS
    SYNONYMS: dict = SYNONYMS
    SHORTCUTS: dict = SHORTCUTS
    CALC_RULES: dict = CALC_RULES
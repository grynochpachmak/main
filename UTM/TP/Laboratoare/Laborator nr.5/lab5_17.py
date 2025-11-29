# lab5_17
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 17: Alege și afișează o lună dintr-un an dat folosind modulul random.

import random

an = int(input("Introduceți anul: "))

luni = [
    "Ianuarie", "Februarie", "Martie", "Aprilie", "Mai", "Iunie",
    "Iulie", "August", "Septembrie", "Octombrie", "Noiembrie", "Decembrie"
]

luna_aleasa = random.choice(luni)
print(f"Pentru anul {an}, luna aleasă aleatoriu este: {luna_aleasa}")
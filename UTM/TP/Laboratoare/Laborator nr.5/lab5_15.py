# lab5_15
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 15: Afișează elementele unui dicționar dat folosind modulul random.

import random

d = {"nume": "Marin", "varsta": 21, "oras": "Chișinău"}

cheie = random.choice(list(d.keys()))
print(cheie, ":", d[cheie])

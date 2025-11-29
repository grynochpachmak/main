# lab5_12
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 12: Generează o listă de 10 numere pare folosind modulul random.

import random

numere_pare = []

while len(numere_pare) < 10:
    n = random.randint(1, 100)
    if n % 2 == 0:
        numere_pare.append(n)

print(numere_pare)

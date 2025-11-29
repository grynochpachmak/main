# lab5_8
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 8: Creează un joc de ghicit numere între 1 și 10 folosind modulul random.

import random

secret = random.randint(1, 10)
incercare = int(input("Ghici numărul (1-10): "))

if incercare == secret:
    print("Ai ghicit!")
else:
    print("Nu ai ghicit. Numărul era:", secret)

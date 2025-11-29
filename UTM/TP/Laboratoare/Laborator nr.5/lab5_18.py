# lab5_18
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 18: Generează și afișează un număr prim între 1 și 50 folosind modulul random

import random

numere_prime = []

for n in range(1, 51):
    if n > 1:
        prim = True
        for i in range(2, int(n**0.5) + 1):
            if n % i == 0:
                prim = False
                break
        if prim:
            numere_prime.append(n)

print(random.choice(numere_prime))

# lab5_5
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 5: Generează o listă de 5 culori aleatorii folosind modulul random și afișează-le.

import random

culori = ["rosu", "verde", "albastru", "galben", "mov", "portocaliu", "negru", "alb"]
lista = [random.choice(culori) for _ in range(5)]
print(lista)

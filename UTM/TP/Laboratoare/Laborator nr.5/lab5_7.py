# lab5_7
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 7: Sortează o listă de numere întregi în ordine crescătoare folosind modulul random.

import random

lista = [random.randint(1, 100) for _ in range(10)]
lista_ordonata = sorted(lista)
print(lista_ordonata)

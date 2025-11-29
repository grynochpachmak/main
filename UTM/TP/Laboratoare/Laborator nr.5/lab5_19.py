# lab5_19
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 19: Afișează și sortează o listă de litere în ordine alfabetică folosind modulul random.

import random
import string

lista = [random.choice(string.ascii_lowercase) for _ in range(5)]
print("Lista inițială:", lista)

lista_sortata = sorted(lista)
print("Lista sortată:", lista_sortata)

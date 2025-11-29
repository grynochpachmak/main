# lab5_11
# November 2025
# Juncu Marin MN-251
# Laborator nr.5: Module și pachete în Python
# Sarcina 11: Afișează conținutul unui fișier text dat folosind modulul os.

import os

if os.path.exists("fisier.txt"):
    with open("fisier.txt", "r") as f:
        print(f.read())
else:
    print("Fișierul nu există.")

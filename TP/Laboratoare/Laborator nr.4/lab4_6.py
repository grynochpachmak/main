# lab4_6.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.6
 
import os

filename = "hello.txt"

if os.path.exists(filename):
    with open(filename, "r") as f:
        lines = f.readlines()

    if len(lines) > 50:
        rezum = lines[:5]

        with open("rezumat.txt", "w") as out:
            out.writelines(rezum)

        print("Fișierul are peste 50 de linii. Rezumatul a fost creat!")
    else:
        print("Fișierul NU are peste 50 de linii.")
else:
    print("Fișierul nu există!")

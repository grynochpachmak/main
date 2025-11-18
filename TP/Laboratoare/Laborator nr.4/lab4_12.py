# lab4_12.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.12: Verifică numărul de linii și adaugă linii noi până când fișierul ajunge la cel puțin 20 de linii.
 
import os

filename = "hello.txt"
minnum = 20

if os.path.exists(filename):
    with open(filename, "r") as f:
        linii = f.readlines()

    linesnum = len(linii)
    print(f"Fișierul are {linesnum} linii.")

    if linesnum < minnum:
        print(f"Fișierul are mai puțin de {minnum} linii. Se adaugă linii...")

        lipsa = minnum - linesnum

        with open(filename, "a") as f:
            for i in range(lipsa):
                f.write(f"Linie automată adăugată #{i+1}\n")

        print("Liniile au fost adăugate cu succes!")
    else:
        print("Fișierul are deja suficiente linii.")
else:
    print("Fișierul nu există!")
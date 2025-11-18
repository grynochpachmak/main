# lab4_13.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.13
 
import os
import string

filename = "hello.txt"

if os.path.exists(filename):

    with open(filename, "r") as f:
        content = f.read()

    if any(c in string.punctuation for c in content):
        print("Fișierul conține caractere de punctuație. Se elimină...")

        wopunct = "".join(
            c for c in content if c not in string.punctuation
        )

        with open("fara_punctuatie.txt", "w") as out:
            out.write(wopunct)

        print('Caracterele de punctuație au fost eliminate în "fara_punctuatie.txt".')

    else:
        print("Fișierul NU conține caractere de punctuație.")
else:
    print("Fișierul nu există!")

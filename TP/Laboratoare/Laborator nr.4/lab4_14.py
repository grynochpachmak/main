# lab4_14.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.14
 
import os

filename = "hello.txt"

if os.path.exists(filename):

    with open(filename, "r") as f:
        content = f.read()

    digitnum = sum(1 for c in content if c.isdigit())

    print(f"Fișierul conține {digitnum} caractere numerice.")

    if digitnum > 30:
        print("Fișierul are peste 30 de cifre. Se extrag numerele...")

        nums = []
        buffer = ""

        for c in content:
            if c.isdigit():
                buffer += c
            else:
                if buffer:
                    nums.append(buffer)
                    buffer = ""
        if buffer:
            nums.append(buffer)

        with open("numere_extrase.txt", "w") as out:
            for n in nums:
                out.write(n + "\n")

        print('Toate numerele au fost extrase în "numere_extrase.txt".')

    else:
        print("Fișierul NU are mai mult de 30 de cifre.")

else:
    print("Fișierul nu există!")

# lab4_10.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.10
 
import os

filename = "hello.txt"

if os.path.exists(filename):

    with open(filename, "r") as f:
        content = f.read()

    if all(c.isalnum() or c.isspace() for c in content):
        print("Fișierul conține NUMAI caractere alfanumerice.")
        print("Convertim literele mici în MAJUSCULE...")

        content_upper = content.upper()

        with open("alfanumeric.txt", "w") as out:
            out.write(content_upper)

        print("Conversia a fost realizată cu succes!")
    else:
        print("Fișierul conține și alte caractere ne-alfanumerice.")
else:
    print("Fișierul nu există!")

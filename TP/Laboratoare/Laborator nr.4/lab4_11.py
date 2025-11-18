# lab4_11.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.11: Numără cuvintele din fișier și creează un rezumat dacă acesta conține exact 100 de cuvinte.
 
import os

filename = "hello.txt"

if os.path.exists(filename):
    with open(filename, "r") as f:
        content = f.read()

    words = content.split()
    wordsnum = len(words)

    print(f"Fișierul conține {wordsnum} cuvinte.")

    if wordsnum == 100:
        print("Fișierul are EXACT 100 de cuvinte. Se creează rezumatul...")

        rezumat = " ".join(words[:10])

        with open("rezumat.txt", "w") as out:
            out.write(rezumat)

        print("Rezumatul a fost creat în 'rezumat.txt'.")
    else:
        print("Fișierul NU are exact 100 de cuvinte.")
else:
    print("Fișierul nu există!")

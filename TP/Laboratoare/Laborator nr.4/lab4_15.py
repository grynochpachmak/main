# lab4_15.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.15: Dacă fișierul este .txt și are cel puțin o linie, găsește linia cu cele mai multe caractere și o salvează în linia_max.txt.
 
import os

filename = "hello.txt"

if os.path.exists(filename):

    if filename.endswith(".txt"):

        with open(filename, "r") as f:
            lines = f.readlines()

        if len(lines) > 0:
            print("Fișierul este .txt și conține cel puțin o linie.")
            print("Se caută linia cu cele mai multe caractere...")

            maxline = max(lines, key=len)

            with open("linia_max.txt", "w") as out:
                out.write(maxline)

            print('Linia cu cele mai multe caractere a fost salvată în "linia_max.txt".')
        else:
            print("Fișierul este .txt dar este gol (nu are linii).")
    else:
        print("Fișierul NU are extensia .txt!")
else:
    print("Fișierul nu există!")

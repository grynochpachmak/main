# lab4_4.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.4
 
import os

if os.path.exists("hello.txt"):
    filename = "hello.txt"

    if filename.endswith(".txt"):
        os.rename(filename, "file.txt")
        print('Fișierul a fost redenumit în "file.txt".')
    else:
        print('Fișierul "hello" nu are extensia ".txt"!')
else:
    print("Fișierul nu există!")
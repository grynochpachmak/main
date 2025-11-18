# lab4_7.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.7: Verifică dacă un anumit caracter apare în fișier și afișează numărul aparițiilor.
 
import os

filename = "hello.txt"
char = "a"

if os.path.exists(filename):
    with open(filename, "r") as f:
        content = f.read()

    if char in content:
        freq = content.count(char)
        print(f'Caracterul "{char}" apare de {freq} ori în fișier.')
    else:
        print(f'Caracterul "{char}" NU se găsește în fișier.')
else:
    print("Fișierul nu există!")

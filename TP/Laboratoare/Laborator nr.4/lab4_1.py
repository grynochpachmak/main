# lab4_1.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.1
 
import os

if os.path.exists("hello.txt"):
    with open("hello.txt") as file:
        content = file.read()
        print(content)
else:
    print("Fișierul nu există!")
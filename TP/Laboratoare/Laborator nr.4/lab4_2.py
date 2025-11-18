# lab4_2.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.2
 
import os

if os.path.exists("hello.txt"):
    size = os.path.getsize("hello.txt")
    if size < 1024:
        print("Fișierul este mai mic de 1024 bytes. Se copiază...")

        with open("hello.txt", "r") as file:
            with open("copy.txt", "w") as copy:
                copy.write(file.read())
    else:
        print("Fișierul este mai mare de 1024 bytes. Nu se copiază.")
else:
    print("Fișierul nu există!")

# lab4_9.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.9: Verifică dacă fișierul hello.txt este vid și îl șterge dacă dimensiunea este 0 bytes.
 
import os

filename = "hello.txt"

if os.path.exists(filename):

    if os.path.getsize(filename) == 0:
        print("Fișierul este VID. Se șterge...")

        os.remove(filename)
        print("Fișierul a fost șters.")
    else:
        print("Fișierul NU este vid. Dimensiunea este:", os.path.getsize(filename), "bytes")

else:
    print("Fișierul nu există!")

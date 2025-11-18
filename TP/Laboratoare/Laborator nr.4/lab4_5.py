#lab4_5.py
# November 2025
# Juncu Marin, gr. MN-251
# Laborator nr.4. Fișiere, prelucrarea fișierelor
# Sarcina nr.5: Afișează data și ora ultimei modificări ale fișierului hello.txt.
 
import os
from datetime import datetime

filename = "hello.txt"

if os.path.isfile(filename):
    t = os.path.getmtime(filename)
    dt = datetime.fromtimestamp(t)
    print("Fișier modificat ultima dată la:", dt.strftime("%d.%m.%Y %H:%M:%S"))
else:
    print("Fișierul nu există!")
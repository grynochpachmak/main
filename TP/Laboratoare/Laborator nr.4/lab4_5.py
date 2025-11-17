import os
from datetime import datetime

filename = "hello.txt"

if os.path.isfile(filename):
    t = os.path.getmtime(filename)
    dt = datetime.fromtimestamp(t)
    print("Fișier modificat ultima dată la:", dt.strftime("%d.%m.%Y %H:%M:%S"))
else:
    print("Fișierul nu există!")
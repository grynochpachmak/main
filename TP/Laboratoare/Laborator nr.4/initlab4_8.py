# initlab4_8.py

content = "Acesta este fișierul pentru lab4_8. Verificăm permisiunea de citire.\n"

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt creat pentru lab4_8.")

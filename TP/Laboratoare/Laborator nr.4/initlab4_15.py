# initlab4_15.py

content = """Scurta.
Aceasta este cea mai lunga linie din fisierul nostru de test pentru lab4_15, contine foarte multe caractere pentru a fi aleasa ca linia maxima.
Alta linie scurta.
"""

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt creat pentru lab4_15 (mai multe linii, una foarte lungă).")

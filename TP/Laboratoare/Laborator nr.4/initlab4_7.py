# initlab4_7.py

content = """Ana are mere și para.
Maria are banana.
Caracterul 'a' apare de multe ori în acest fișier pentru lab4_7.
"""

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt creat pentru lab4_7 (multe 'a').")

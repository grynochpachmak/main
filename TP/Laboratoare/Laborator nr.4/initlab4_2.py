# initlab4_2.py

content = """Acesta este fișierul pentru lab4_2.
Are dimensiune mai mică de 1024 bytes, deci va fi copiat în copy.txt.
"""

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt creat pentru lab4_2 (sub 1024 bytes).")

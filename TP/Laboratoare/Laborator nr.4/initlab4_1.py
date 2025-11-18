# initlab4_1.py

content = "Hello, World!\nAcesta este fișierul pentru lab4_1.\n"

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt creat pentru lab4_1.")

# initlab4_5.py

content = "Fișier pentru lab4_5. Aici verificăm data ultimei modificări.\n"

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt creat pentru lab4_5.")

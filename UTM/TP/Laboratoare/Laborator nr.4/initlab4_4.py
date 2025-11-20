# initlab4_4.py

content = "Acesta este fișierul hello.txt pentru lab4_4. Va fi redenumit în file.txt.\n"

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt creat pentru lab4_4.")

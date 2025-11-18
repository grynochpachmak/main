# initlab4_14.py

content = "Numere: 12345678901234567890123456789012345 si inca 67890.\n"

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

digitnum = sum(1 for c in content if c.isdigit())
print(f"hello.txt creat pentru lab4_14, conține {digitnum} cifre.")

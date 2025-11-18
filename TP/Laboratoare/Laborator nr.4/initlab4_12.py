# initlab4_12.py

with open("hello.txt", "w", encoding="utf-8") as f:
    for i in range(1, 11):  # 10 linii
        f.write(f"Linia {i}: pentru lab4_12.\n")

print("hello.txt (10 linii) creat pentru lab4_12.")

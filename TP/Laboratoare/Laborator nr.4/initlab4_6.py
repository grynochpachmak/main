# initlab4_6.py

with open("hello.txt", "w", encoding="utf-8") as f:
    for i in range(1, 61):  # 60 linii
        f.write(f"Linia {i}: text pentru lab4_6.\n")

print("hello.txt (60 linii) creat pentru lab4_6.")

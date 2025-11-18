# initlab4_3.py

content = """Hello, World!
People from all over the World use Python.
World of programming and People who love coding.
"""

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt creat pentru lab4_3 (conține 'World').")

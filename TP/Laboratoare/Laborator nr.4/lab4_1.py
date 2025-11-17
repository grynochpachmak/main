import os

if os.path.exists("hello.txt"):
    with open("hello.txt") as file:
        content = file.read()
        print(content)
else:
    print("Fișierul nu există!")
import os

filename = "hello.txt"
caracter = "a"

if os.path.exists(filename):
    with open(filename, "r") as f:
        content = f.read()

    if caracter in content:
        aparitii = content.count(caracter)
        print(f'Caracterul "{caracter}" apare de {aparitii} ori în fișier.')
    else:
        print(f'Caracterul "{caracter}" NU se găsește în fișier.')
else:
    print("Fișierul nu există!")

import os

filename = "hello.txt"

if os.path.exists(filename):

    if os.access(filename, os.R_OK):
        print("Fișierul are permisiune de citire. Conținutul este:\n")

        with open(filename, "r") as f:
            content = f.read()
            print(content)

    else:
        print("Fișierul EXISTĂ, dar NU are permisiune de citire!")
else:
    print("Fișierul nu există!")
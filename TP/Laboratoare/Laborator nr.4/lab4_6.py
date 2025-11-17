import os

filename = "hello.txt"

if os.path.exists(filename):
    with open(filename, "r") as f:
        linii = f.readlines()

    if len(linii) > 50:
        rezumat = linii[:5]

        with open("rezumat.txt", "w") as out:
            out.writelines(rezumat)

        print("Fișierul are peste 50 de linii. Rezumatul a fost creat!")
    else:
        print("Fișierul NU are peste 50 de linii.")
else:
    print("Fișierul nu există!")

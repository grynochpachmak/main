import os

filename = "hello.txt"

if os.path.exists(filename):
    with open(filename, "r") as f:
        content = f.read()

    cuvinte = content.split()
    nr_cuvinte = len(cuvinte)

    print(f"Fișierul conține {nr_cuvinte} cuvinte.")

    if nr_cuvinte == 100:
        print("Fișierul are EXACT 100 de cuvinte. Se creează rezumatul...")

        rezumat = " ".join(cuvinte[:10])

        with open("rezumat.txt", "w") as out:
            out.write(rezumat)

        print("Rezumatul a fost creat în 'rezumat.txt'.")
    else:
        print("Fișierul NU are exact 100 de cuvinte.")
else:
    print("Fișierul nu există!")

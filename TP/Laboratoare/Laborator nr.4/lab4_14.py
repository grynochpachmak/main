import os

nume_fisier = "hello.txt"

if os.path.exists(nume_fisier):

    with open(nume_fisier, "r") as f:
        content = f.read()

    nr_cifre = sum(1 for c in content if c.isdigit())

    print(f"Fișierul conține {nr_cifre} caractere numerice.")

    if nr_cifre > 30:
        print("Fișierul are peste 30 de cifre. Se extrag numerele...")

        numere = []
        buffer = ""

        for c in content:
            if c.isdigit():
                buffer += c
            else:
                if buffer:
                    numere.append(buffer)
                    buffer = ""
        if buffer:
            numere.append(buffer)

        with open("numere_extrase.txt", "w") as out:
            for n in numere:
                out.write(n + "\n")

        print('Toate numerele au fost extrase în "numere_extrase.txt".')

    else:
        print("Fișierul NU are mai mult de 30 de cifre.")

else:
    print("Fișierul nu există!")

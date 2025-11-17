import os

filename = "hello.txt"
numar_minim = 20

if os.path.exists(filename):
    with open(filename, "r") as f:
        linii = f.readlines()

    nr_linii = len(linii)
    print(f"Fișierul are {nr_linii} linii.")

    if nr_linii < numar_minim:
        print(f"Fișierul are mai puțin de {numar_minim} linii. Se adaugă linii...")

        lipsa = numar_minim - nr_linii

        with open(filename, "a") as f:
            for i in range(lipsa):
                f.write(f"Linie automată adăugată #{i+1}\n")

        print("Liniile au fost adăugate cu succes!")
    else:
        print("Fișierul are deja suficiente linii.")
else:
    print("Fișierul nu există!")
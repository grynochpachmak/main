import os

nume_fisier = "hello.txt"

if os.path.exists(nume_fisier):

    if nume_fisier.endswith(".txt"):

        with open(nume_fisier, "r") as f:
            linii = f.readlines()

        if len(linii) > 0:
            print("Fișierul este .txt și conține cel puțin o linie.")
            print("Se caută linia cu cele mai multe caractere...")

            linia_max = max(linii, key=len)

            with open("linia_max.txt", "w") as out:
                out.write(linia_max)

            print('Linia cu cele mai multe caractere a fost salvată în "linia_max.txt".')
        else:
            print("Fișierul este .txt dar este gol (nu are linii).")
    else:
        print("Fișierul NU are extensia .txt!")
else:
    print("Fișierul nu există!")

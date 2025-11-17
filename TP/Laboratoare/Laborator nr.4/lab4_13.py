import os
import string

nume_fisier = "hello.txt"

if os.path.exists(nume_fisier):

    with open(nume_fisier, "r") as f:
        content = f.read()

    if any(c in string.punctuation for c in content):
        print("Fișierul conține caractere de punctuație. Se elimină...")

        content_fara_punct = "".join(
            c for c in content if c not in string.punctuation
        )

        with open("fara_punctuatie.txt", "w") as out:
            out.write(content_fara_punct)

        print('Caracterele de punctuație au fost eliminate în "fara_punctuatie.txt".')

    else:
        print("Fișierul NU conține caractere de punctuație.")
else:
    print("Fișierul nu există!")

import os

if os.path.exists("hello.txt"):
    filename = "hello.txt"

    if filename.endswith(".txt"):
        os.rename(filename, "file.txt")
        print('Fișierul a fost redenumit în "file.txt".')
    else:
        print('Fișierul "hello" nu are extensia ".txt"!')
else:
    print("Fișierul nu există!")
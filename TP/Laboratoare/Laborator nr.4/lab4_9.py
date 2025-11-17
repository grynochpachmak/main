import os

filename = "hello.txt"

if os.path.exists(filename):

    if os.path.getsize(filename) == 0:
        print("Fișierul este VID. Se șterge...")

        # 3. Ștergem fișierul
        os.remove(filename)
        print("Fișierul a fost șters.")
    else:
        print("Fișierul NU este vid. Dimensiunea este:", os.path.getsize(filename), "bytes")

else:
    print("Fișierul nu există!")

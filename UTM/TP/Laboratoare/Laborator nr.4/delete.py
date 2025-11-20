import os

deleted = 0

for file in os.listdir():
    if file.endswith(".txt"):
        os.remove(file)
        print(f"Șters: {file}")
        deleted += 1

if deleted == 0:
    print("Nu există fișiere .txt de șters.")
else:
    print(f"Total fișiere șterse: {deleted}")

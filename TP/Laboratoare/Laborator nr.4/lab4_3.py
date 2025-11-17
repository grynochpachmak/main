import os

if os.path.exists("hello.txt"):
    with open("hello.txt", "r") as file:
        content = file.read()

        if "World" in content:
            newcontent = content.replace("World", "People")
            with open("people.txt", "w") as people:
                people.write(newcontent)
        else:
            print('Cheia "World" nu exista!')
else:
    print("Fișierul nu există!")
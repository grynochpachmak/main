# initlab4_13.py

content = """Salut, lume! Acesta este un test: are virgule, puncte, semne de intrebare?
Da, are! Are si paranteze (ca exemplu), precum si alte semne: #, @, %, &.
"""

with open("hello.txt", "w", encoding="utf-8") as f:
    f.write(content)

print("hello.txt cu punctuație creat pentru lab4_13.")

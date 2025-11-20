# September 2025
# Juncu Marin, gr. MN-251
# Laborator nr. 2. Structuri de control conditionale. Structuri repetitive. Module - math, random, datetime, time.
# Sarcina: Numarare litere mari si mici

string = input("Introduceti un sir de caractere: ")
countUpper = 0
countLower = 0
for i in string:
    if i.isupper():
        countUpper += 1
    else:
        countLower += 1
print("Sunt {} litere mari si {} litere mici.".format(countUpper, countLower))
# September 2025
# Juncu Marin, gr. MN-251
# Laborator nr. 2. Structuri de control conditionale. Structuri repetitive. Module - math, random, datetime, time.
# Sarcina: Verificare palindrom

word = input("Introduceti un cuvant: ")
reversedWord = ''
for i in reversed(word):
    reversedWord += i 
if word == reversedWord:
    print("'{}' este palindrom.".format(word))
else:
    print("'{}' nu este palindrom.".format(word))
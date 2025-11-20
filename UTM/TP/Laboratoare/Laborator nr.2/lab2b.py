# September 2025
# Juncu Marin, gr. MN-251
# Laborator nr. 2. Structuri de control conditionale. Structuri repetitive. Module - math, random, datetime, time.
# Sarcina: Cautare intr-o lista

lista = ["Marin", "Ana", "Gheorghe", "Augustina", "Artiom"]
nume = input("Introduceti un nume: ")
if nume in lista:
    print("Numele '{}' se afla in lista.".format(nume))
else:
    print("Numele '{}' nu se afla in lista.".format(nume))
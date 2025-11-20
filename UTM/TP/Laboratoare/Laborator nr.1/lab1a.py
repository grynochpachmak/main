# September 2025
# Juncu Marin, gr. MN-251
# Laborator nr. 1. Tipuri de date. Șiruri de caractere. Operațiuni de bază
# Sarcina: Scrieți un program care afișează numele și două numere introduse de utilizator și afișează operațiunile de bază cu aceste numere.

name = input("Introduceti numele dumneavoastra: ") # Introducerea numelui
a = int(input("Introduceti un numar: ")) # Introducerea primei variabila
b = int(input("Introduceti un alt numar: ")) # Introducerea a doua variabila

print("\nStimate " + name + ",") # Afisarea numelui
print("Numerele introduse de dvs. sunt: " + str(a) + ", " + str(b) + ".") # Afisarea variabilelor
print("Adunarea: a + b = " + str(a+b) +".") # Afisarea adunarii
print("Scaderea: a - b = " + str(a-b) +".") # Afisarea scaderii
print("Inmultirea: a * b = " + str(a*b) +".") # Afisarea inmultirii
print("Impartirea: a / b = " + str(round((a/b), 2)) +".") # Afisarea impartirii
print("Impartirea intreaga: a // b = " + str(a//b) +".") # Afisarea impartirii intregi
print("Restul impartirii: a % b = " + str(a%b) +".") # Afisarea restului impartirii
print("Puterile: a ** b = " + str(a**b) +".") # Afisarea ridicarii la putere
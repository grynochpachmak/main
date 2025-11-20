# October 2025
# Juncu Marin, gr. MN-251
# Laborator nr. 3. Liste și dicționare, funcţii cu argumente, funcții built-in. Fişiere
# Sarcina nr.2: Modifică numere_pare(lista) astfel încât să returneze și numărul total de numere pare găsite.

def numere_pare(lista):
    rezultat = []
    for x in lista:
        if x % 2 == 0:
            rezultat.append(x)
    return rezultat, len(rezultat)

valori = [1, 2, 3, 4, 5, 6, 7, 8]
lista_pare, numar_total = numere_pare(valori)
print("Numere pare găsite:", lista_pare)
print("Numărul total de numere pare:", numar_total)
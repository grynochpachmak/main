# October 2025
# Juncu Marin, gr. MN-251
# Laborator nr. 3. Liste și dicționare, funcţii cu argumente, funcții built-in. Fişiere
# Sarcina nr.3: Extinde numere_pare(lista) pentru a returna și suma numerelor pare, nu doar lista lor și numărul lor.

def numere_pare(lista):
    rezultat = []
    suma = 0
    for x in lista:
        if x % 2 == 0:
            rezultat.append(x)
            suma += x
    return rezultat, len(rezultat), suma


valori = [1, 2, 3, 4, 5, 6, 8, 9]
lista_pare, numar_total, suma_pare = numere_pare(valori)
print("Numere pare găsite:", lista_pare)
print("Numărul total de numere pare:", numar_total)
print("Suma numerelor pare:", suma_pare)
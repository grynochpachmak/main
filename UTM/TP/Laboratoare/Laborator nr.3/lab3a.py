# October 2025
# Juncu Marin, gr. MN-251
# Laborator nr. 3. Liste și dicționare, funcţii cu argumente, funcții built-in. Fişiere
# Sarcina nr.1: Scrie o funcție numere_pare(lista) care primește o listă de numere și returnează doar cele pare.

def numere_pare(lista):
    rezultat = []
    for x in lista:
        if x % 2 == 0:
            rezultat.append(x)
    return rezultat

valori = [1, 2, 3, 4, 5, 6, 7, 8]
print("Numere pare găsite:", numere_pare(valori))
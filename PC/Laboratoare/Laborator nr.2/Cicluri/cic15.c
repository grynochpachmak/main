// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a calcula produsul cifrelor unui număr. 

#include <stdio.h>

int main() {
    int n, temp, produs = 1;
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    int num = n; // p/u rezultat

    while(n > 0) {
    temp = n % 10;
    n /= 10;
    produs *= temp;
    }

    printf("\nProdusul cifrelor numarului %d este %d.", num, produs);

    return 0;
}
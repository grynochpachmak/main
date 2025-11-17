// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a verifica dacă un număr este par sau impar.

#include <stdio.h>

int main() {
    int x;

    printf("Introduceti un numar intreg: ");
    scanf("%d", &x);

    if (x % 2 == 0) {
        printf("Numarul %d este par.", x);
    } else {
        printf("Numarul %d este impar.", x);
    }

    return 0;
}
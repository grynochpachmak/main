// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a verifica dacă un număr este negativ, pozitiv sau zero.

#include <stdio.h>

int main() {
    int x;

    printf("Introduceti un numar intreg: ");
    scanf("%d", &x);

    if (x > 0) {
        printf("Numarul %d este mai mare ca 0.", x);
    }
    else if (x < 0) {
        printf("Numarul %d este mai mic ca 0.", x);
    }
    else {
        printf("Numarul %d este egal cu 0.", x);
    }

    return 0;
}
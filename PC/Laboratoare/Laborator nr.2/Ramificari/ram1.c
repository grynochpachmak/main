// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a găsi maxim între două numere.

#include <stdio.h>

int main() {
    int a, b;

    printf("Introduceti un numar intreg: ");
    scanf("%d", &a);
    
    printf("Introduceti un alt numar intreg: ");
    scanf("%d", &b);

    if (a > b) {
        printf("Numarul %d este mai mare ca %d.", a, b);
    }
    else {
        printf("Numarul %d este mai mare ca %d.", b, a);
    }

    return 0;
}
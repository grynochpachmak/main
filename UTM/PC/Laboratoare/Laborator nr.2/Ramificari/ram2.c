// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a găsi maxim între trei numere.

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Introduceti un numar intreg: ");
    scanf("%d", &a);
    
    printf("Introduceti un alt numar intreg: ");
    scanf("%d", &b);

    printf("Introduceti un al treilea numar intreg: ");
    scanf("%d", &c);

    if (a > b && a > c) {
        printf("Numarul %d este mai mare ca %d si %d.", a, b, c);
    }
    else if (b > a && b > c) {
        printf("Numarul %d este mai mare ca %d si %d.", b, a, c);
    }
    else {
        printf("Numarul %d este mai mare ca %d si %d.", c, a, b);

    }

    return 0;
}
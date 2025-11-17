// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a verifica dacă un număr este divizibil cu 5 și 11 sau nu.

#include <stdio.h>

int main() {
    int x;

    printf("Introduceti un numar intreg: ");
    scanf("%d", &x);

    if (x % 5 == 0 && x % 11 == 0) {
        printf("Numarul %d este divizibil cu 5 si 11.", x);
    } else {
        printf("Numarul %d nu este divizibil cu 5 si 11.", x);
    }
       
    return 0;
}
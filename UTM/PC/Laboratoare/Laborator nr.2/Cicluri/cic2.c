// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a imprima toate numerele naturale invers (de la n la 1). - folosind bucla while.

#include <stdio.h>

int main() {
    int n;
    printf("Cate numere doriti sa se afiseze? ");
    scanf("%d", &n);

    while(n >= 0) {
        printf("%d\n", n);
        n--;
    }

    return 0;
}
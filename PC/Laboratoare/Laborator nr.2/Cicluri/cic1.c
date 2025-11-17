// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a imprima toate numerele naturale de la 1 la n. - folosind bucla while.

#include <stdio.h>

int main() {
    int n;
    printf("Cate numere doriti sa se afiseze? ");
    scanf("%d", &n);

    int count = 1;
    while(count <= n) {
        printf("%d\n", count);
        count++;
    }

    return 0;
}
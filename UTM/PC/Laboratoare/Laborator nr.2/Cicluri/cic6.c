// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a găsi suma tuturor numerelor naturale cuprinse între 1 și n.

#include <stdio.h>

int main() {
    int n;
    printf("Cate numere doriti sa sumati? ");
    scanf("%d", &n);

    int sum = 0;
    int count = 0;
    while(count <= n) {
        sum += count;
        count++;
    }

    printf("\nSuma a %d numere = %d", n, sum);

    return 0;
}
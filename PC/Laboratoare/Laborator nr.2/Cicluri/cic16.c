// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a introduce un număr și imprimați invers.

#include <stdio.h>

int main() {
    int n, temp;
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    printf("\nInversul: ");

    while(n > 0) {
    temp = n % 10;
    n /= 10;
    printf("%d", temp);
    }

    return 0;
}
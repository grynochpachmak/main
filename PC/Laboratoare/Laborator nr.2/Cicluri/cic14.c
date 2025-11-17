// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a calcula suma cifrelor unui număr.

#include <stdio.h>

int main() {
    int n, temp, sum = 0;
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    int num = n; // p/u rezultat

    while(n > 0) {
    temp = n % 10;
    n /= 10;
    sum += temp;
    }

    printf("\nSuma cifrelor numarului %d este %d.", num, sum);

    return 0;
}
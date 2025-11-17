// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a verifica dacă un număr este palindrom sau nu.

#include <stdio.h>

int main() {
    int n, last, invers;
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    int num = n;

    while(n > 0) {
    last = n % 10;
    invers = invers * 10 + last;
    n /= 10;
    }

    if(num == invers)
        printf("Numarul %d este palindrom.", num);
    else
        printf("Numarul %d nu este palindrom.", num);

    return 0;
}
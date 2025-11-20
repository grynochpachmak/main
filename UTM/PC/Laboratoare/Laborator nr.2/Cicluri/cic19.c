// Septembrie 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a introduce un număr și a-l imprima în cuvinte.

#include <stdio.h>

int main() {
    int n, cifra, invers = 0;
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    int temp = n;
    while (temp > 0) {
        invers = invers * 10 + temp % 10;
        temp /= 10;
    }

    printf("Numarul in cuvinte: ");
    while (invers > 0) {
        cifra = invers % 10;
        switch (cifra) {
            case 0: printf("zero "); break;
            case 1: printf("unu "); break;
            case 2: printf("doi "); break;
            case 3: printf("trei "); break;
            case 4: printf("patru "); break;
            case 5: printf("cinci "); break;
            case 6: printf("sase "); break;
            case 7: printf("sapte "); break;
            case 8: printf("opt "); break;
            case 9: printf("noua "); break;
        }
        invers /= 10;
    }

    return 0;
}
// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a schimba prima și ultima cifră a unui număr.

#include <stdio.h>

int main() {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    int temp = n;
    int last = temp % 10;
    int first;
    int pow10 = 1;

    while (temp >= 10) {
        temp /= 10;
        pow10 *= 10;
    }
    first = temp;

    int middle = (n % pow10) / 10;

    int new_n = last * pow10 + middle * 10 + first;

    printf("\nNumarul initial: %d\n", n);
    printf("Prima cifra: %d\n", first);
    printf("Ultima cifra: %d\n", last);
    printf("Numarul obtinut dupa schimb: %d\n", new_n);

    return 0;
}
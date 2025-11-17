// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina:	Scrieți un program C pentru a găsi prima și ultima cifră a unui număr. 

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    int first = n;
    while(first >= 10) {
        first /=10;
    }

    int last = n % 10;

    printf("Prima cifra al numarului %d este %d.\n", n, first );
    printf("Ultima cifra al numarului %d este %d.\n", n, last);

    return 0;
}
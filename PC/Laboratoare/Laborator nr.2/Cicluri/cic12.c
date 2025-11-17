// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina:	Scrieți un program C pentru a găsi suma primei și ultimei cifre a unui număr. 

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

    printf("Suma primei si ultimei cifre al numarului %d: %d + %d = %d.", n, first, last, first + last);

    return 0;
}
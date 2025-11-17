// Septembrie 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a găsi frecvența fiecărei cifre într-un număr întreg dat.

#include <stdio.h>

int main() {
    int n, cifra;
    int f0=0, f1=0, f2=0, f3=0, f4=0, f5=0, f6=0, f7=0, f8=0, f9=0;

    printf("Introduceti un numar: ");
    scanf("%d", &n);

    while (n > 0) {
        cifra = n % 10;
        if (cifra == 0) f0++;
        else if (cifra == 1) f1++;
        else if (cifra == 2) f2++;
        else if (cifra == 3) f3++;
        else if (cifra == 4) f4++;
        else if (cifra == 5) f5++;
        else if (cifra == 6) f6++;
        else if (cifra == 7) f7++;
        else if (cifra == 8) f8++;
        else if (cifra == 9) f9++;
        n /= 10;
    }

    printf("Frecventa fiecarei cifre:\n");
    if (f0 > 0) printf("Cifra 0 apare de %d ori\n", f0);
    if (f1 > 0) printf("Cifra 1 apare de %d ori\n", f1);
    if (f2 > 0) printf("Cifra 2 apare de %d ori\n", f2);
    if (f3 > 0) printf("Cifra 3 apare de %d ori\n", f3);
    if (f4 > 0) printf("Cifra 4 apare de %d ori\n", f4);
    if (f5 > 0) printf("Cifra 5 apare de %d ori\n", f5);
    if (f6 > 0) printf("Cifra 6 apare de %d ori\n", f6);
    if (f7 > 0) printf("Cifra 7 apare de %d ori\n", f7);
    if (f8 > 0) printf("Cifra 8 apare de %d ori\n", f8);
    if (f9 > 0) printf("Cifra 9 apare de %d ori\n", f9);

    return 0;
}
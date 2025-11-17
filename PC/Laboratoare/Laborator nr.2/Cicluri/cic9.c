// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a imprima tabelul de înmulțire a oricărui număr. 

#include <stdio.h>

int main() {
    int n;

    while(1) {
        printf("Introduceti un numar (de la 1 la 9): ");
        scanf ("%d", &n);

        if(n >= 1 && n <= 9) {
            printf("\n 1 * %d = %d\n", n, n*1);
            printf(" 2 * %d = %d\n", n, n*2);
            printf(" 3 * %d = %d\n", n, n*3);
            printf(" 4 * %d = %d\n", n, n*4);
            printf(" 5 * %d = %d\n", n, n*5);
            printf(" 6 * %d = %d\n", n, n*6);
            printf(" 7 * %d = %d\n", n, n*7);
            printf(" 8 * %d = %d\n", n, n*8);
            printf(" 9 * %d = %d\n", n, n*9);
            printf("10 * %d = %d\n", n, n*10);
            break;
        } else {
            printf("Nu a-ti introdus un numar din diapazonul 1-9!");
            continue;
        }
    }
}
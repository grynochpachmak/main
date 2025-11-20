// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a imprima toate numerele impare între 1 și 100. 

#include <stdio.h>

int main() {
    int n = 1;
    while(n <= 100) {
        printf("%d ", n);
        n += 2;
    }

    return 0;
}
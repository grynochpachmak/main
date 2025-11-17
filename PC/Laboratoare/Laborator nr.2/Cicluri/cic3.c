// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a imprima toate alfabetele de la a la z. - folosind bucla while

#include <stdio.h>

int main() {
    char letter = 'A';
    while(letter <= 'Z') {
        printf("%c ", letter);
        letter++;
    }

    return 0;
}
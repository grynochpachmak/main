// Septembrie 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a imprima toate caracterele ASCII cu valorile lor.

#include <stdio.h>

int main() {
    printf("Tabelul caracterelor ASCII:\n");
    for (int i = 0; i <= 127; i++) {
        printf("Cod %d: %c\n", i, i);
    }

    return 0;
}
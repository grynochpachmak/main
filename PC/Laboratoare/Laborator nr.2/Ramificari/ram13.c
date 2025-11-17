// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a număra numărul total de note într-o anumită cantitate. 

#include <stdio.h>

int main() {
    int nota, count = 0;

    printf("Introduceti notele (separate prin enter, terminati cu -1):\n");

    while(1) {
        scanf("%d", &nota);
        if (nota == -1) break;
        count++;
    }

    printf("Ati introdus %d note.\n", count);

    return 0;
}
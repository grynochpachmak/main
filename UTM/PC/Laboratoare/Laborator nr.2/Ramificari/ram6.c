// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a verifica dacă un an este bisect sau nu.

#include <stdio.h>

int main() {
    int an;

    printf("Introduceti un an: ");
    scanf("%d", &an);

    if ((an % 400 == 0) || (an % 4 == 0 && an % 100 != 0)) {
        printf("Anul %d este bisect.", an);
    } else {
        printf("Anul %d NU este bisect.", an);
    }

    return 0;
}
// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a introduce orice caracter și verificați dacă este alfabet, cifră sau caracter special. 

#include <stdio.h>

int main() {
    char c;

    printf("Introduceti un caracter: ");
    scanf("%c", &c);

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        printf("Caracterul '%c' este o litera din alfabet.", c);
    } else if (c >= '0' && c <= '9') {
        printf("Caracterul '%c' este o cifra.", c);
    } else {
        printf("Caracterul '%c' este un caracter special.", c);
    }

    return 0;
}

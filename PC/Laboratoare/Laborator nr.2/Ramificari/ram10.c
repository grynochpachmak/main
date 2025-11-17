// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a verifica dacă un caracter este cu majuscule sau minuscule.

#include <stdio.h>

int main() {
    char c;

    printf("Introduceti un caracter: ");
    scanf("%c", &c);

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        if (c >= 'A' && c <= 'Z') {
            printf("Caracterul '%c' este o majuscula.", c);
        } else {
            printf("Caracterul '%c' este o minuscula.", c);
        }
    } else {
        printf("Caracterul '%c' nu este o litera din alfabet.", c);
    }

    return 0;
}

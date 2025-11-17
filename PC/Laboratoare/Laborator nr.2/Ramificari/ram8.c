// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a introduce orice alfabet și verificați dacă este vocală sau consoană.

#include <stdio.h>

int main() {
    char c;

    printf("Introduceti un caracter: ");
    scanf("%c", &c);

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'|| c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            printf("Caracterul '%c' este o vocala.", c);
        } else {
            printf("Caracterul '%c' este o consoana.", c);
        }
    } else {
        printf("Caracterul '%c' nu este o litera din alfabet.", c);
    }

    return 0;
}
// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a introduce numărul lunii și a imprima numărul de zile din luna respectivă. 

#include <stdio.h>

int main() {
    int luna;

    printf("Introduceti numarul lunii (1-12): ");
    scanf("%d", &luna);

    switch(luna) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("In luna %d sunt 31 de zile.", luna);
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            printf("In luna %d sunt 30 de zile.", luna);
            break;

        case 2:
            printf("In luna %d sunt 28 sau 29 de zile.", luna);
            break;

        default:
            printf("Nu ati introdus un numar corect!");
            break;
    }

    return 0;
}
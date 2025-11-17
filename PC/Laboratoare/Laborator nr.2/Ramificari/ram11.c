// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a introduce numărul săptămânii și a imprima ziua săptămânii.

#include <stdio.h>

int main() {
    int zi;

    printf("Introduceti numarul zilei din saptamana (1-7): ");
    scanf("%d", &zi);

    switch(zi) {
        case 1:
            printf("Luni.");
            break;
        case 2:
            printf("Marti.");
            break;
        case 3:
            printf("Miercuri.");
            break;
        case 4:
            printf("Joi.");
            break;
        case 5:
            printf("Vineri.");
            break;
        case 6:
            printf("Sambata.");
            break;
        case 7:
            printf("Duminica.");
            break;
        default:
            printf("Nu a-ti introdus un numar corect!");
            break;
    }
    
    return 0;
}
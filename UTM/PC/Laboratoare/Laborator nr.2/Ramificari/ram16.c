// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina:	Scrieți un program C pentru a verifica dacă triunghiul este echilateral, isoscel sau triunghi scalen.

#include <stdio.h>

int main() {
    int select;

    while (1) {
        printf("Alegeti cum doriti sa verificati validitatea triunghiului:\n");
        printf("1 - dupa laturi\n");
        printf("2 - dupa unghiuri\n");
        printf("Optiunea: ");
        scanf("%d", &select);

        if (select == 1 || select == 2) {
            break;
        } else {
            printf("\nEroare! Introduceti 1 sau 2.\n\n");
        }
    }

    if (select == 1) {
        printf("\nAti ales verificarea dupa laturi.\n");
        
        int a, b, c;

            printf("Introduceti lungimea pentru prima latura al triunghiului: ");
            scanf("%d", &a);

            printf("Introduceti lungimea pentru al doua latura al triunghiului: ");
            scanf("%d", &b);

            printf("Introduceti lungimea pentru al treiea latura al triunghiului: ");
            scanf("%d", &c);

            if((a + b) > c && (a + c) > b && (b + c) > a) {
                printf("Triunghiul este valid.");
            } else {
                printf("Triunghiul nu este valid.");
            }

    } else {
        printf("\nAti ales verificarea dupa unghiuri.\n");

            int a, b, c;

            printf("Introduceti masura de grade pentru primul unghi al triunghiului: ");
            scanf("%d", &a);

            printf("Introduceti masura de grade pentru al doilea unghi al triunghiului: ");
            scanf("%d", &b);

            printf("Introduceti masura de grade pentru al treilea unghi al triunghiului: ");
            scanf("%d", &c);

            if((a + b + c) == 180) {
                printf("Triunghiul este valid.");
            } else {
                printf("Triunghiul nu este valid.");
            }

    }

    return 0;
}
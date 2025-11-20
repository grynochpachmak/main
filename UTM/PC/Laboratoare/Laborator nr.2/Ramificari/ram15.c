// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina:	Scrieți un program C pentru a introduce toate laturile unui triunghi și verificați dacă triunghiul este valid sau nu. 

#include <stdio.h>

int main() {

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

    return 0;
}
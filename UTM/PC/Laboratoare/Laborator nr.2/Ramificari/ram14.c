// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a introduce unghiurile unui triunghi și verificați dacă triunghiul este valid sau nu. 

#include <stdio.h>

int main() {

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

    return 0;
}
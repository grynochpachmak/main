// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a număra numărul de cifre dintr-un număr. 

// #include <stdio.h>
// #include <string.h>

// int main() {
//     int n;
//     char str[12];

//     printf("Introduceti un numar: ");
//     scanf("%d", &n);

//     sprintf(str, "%d", n); // conversie

//     printf("Numarul de cifre din numar: %d", strlen(str));

//     return 0;
// }

#include <stdio.h>

int main() {
    int n, count = 0;

    printf("Introduceti un numar: ");
    scanf("%d", &n);

    int num = (n < 0) ? -n : n;

    if (num == 0) {
        count = 1;
    } else {
        while (num > 0) {
            num /= 10;
            count++;
        }
    }

    printf("Numarul de cifre din numar: %d\n", count);

    return 0;
}



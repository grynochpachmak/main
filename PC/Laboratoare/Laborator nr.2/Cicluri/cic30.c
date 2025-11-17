// Septembrie 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a verifica dacă un număr este sau nu numărul Armstrong. 

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    int temp = n;
    int power = 0;

    int copy = n;
    while (copy > 0) {
        copy /= 10;
        power++;
    }

    int arm = 0;

    copy = n;
    while (copy > 0) {
        arm += pow(copy % 10, power);
        copy /= 10;
    }

    printf("Armstrong = %d\n", arm);

    if(arm == temp) {
        printf("%d este Armstrong.\n", temp);
    } else {
        printf("%d nu este Armstrong.\n", temp);
    }

    return 0;
}
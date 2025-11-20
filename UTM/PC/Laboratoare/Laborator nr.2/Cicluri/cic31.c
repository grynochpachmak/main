// Septembrie 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a imprima toate numerele Armstrong cuprinse între 1 și n. 

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        int temp = i;
        int power = 0;

        int copy = i;
        while (copy > 0) {
            copy /= 10;
            power++;
        }

        int arm = 0;

        copy = i;
        while (copy > 0) {
            arm += pow(copy % 10, power);
            copy /= 10;
        }

        if(arm == temp) {
            printf("%d este Armstrong.\n", temp);
        }
    }

    return 0;
}
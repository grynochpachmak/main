// September 2025
// Juncu Marin, gr. MN-251
// Laborator nr.2: Instructiunile de ramificare si ciclice
// Sarcina: Scrieți un program C pentru a găsi suma tuturor numerelor pare între 1 și n. 

#include <stdio.h>

#include <stdio.h>

int main() {
    int n;

    while (1) {
        printf("Care valoare e maximala (para)? ");
        scanf("%d", &n);

        if (n % 2 == 0) {
            int sum = 0;
            int count = 2;
            while (count <= n) {
                sum += count;
                count += 2;
            }
            printf("Suma numerelor pare de la 1 la %d este: %d\n", n, sum);
            break;
        } else {
            printf("Ati introdus un numar impar.\n");
            continue;
        }
    }

    return 0;
}

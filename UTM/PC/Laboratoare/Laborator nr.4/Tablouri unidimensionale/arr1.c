// October 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.1: Scrieți un program C pentru a citi și a imprima elementele unui tablou. - folosind recursia.

#include <stdio.h>

void citire(int a[], int n, int i) {
    if (i == n) return;
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
    citire(a, n, i + 1);
}   

void afisare(int a[], int n, int i) {
    if (i == n) return;
    printf("a[%d] = %d\n", i, a[i]);
    afisare(a, n, i + 1);
}

int main() {
    int n;
    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);
    int a[n];
    citire(a, n, 0);
    printf("\nElementele sunt:\n");
    afisare(a, n, 0);

    return 0;
}
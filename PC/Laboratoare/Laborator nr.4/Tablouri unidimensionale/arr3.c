// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.3: Scrieți un program C pentru a găsi suma tuturor elementelor tabloului - folosind recursia.

#include <stdio.h>

void citire(int a[], int n, int i) {
    if (i == n) return;
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
    citire(a, n, i + 1);
}

void suma(int a[], int n, int i, int *s) {
    if (i == n) return;
    *s += a[i];
    suma(a, n, i + 1, s);
}

int main() {
    int n;
    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);
    int a[n];
    citire(a, n, 0);
    int s = 0;
    suma(a, n, 0, &s);
    printf("\nSuma elementelor tabloului este: %d\n", s);
    
    return 0;
}

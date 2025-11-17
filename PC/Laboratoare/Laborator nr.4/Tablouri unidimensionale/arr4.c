// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.4: Scrieți un program C pentru a găsi elementul maxim și minim într-un tablou - folosind recursia.

#include <stdio.h>

void citire(int a[], int n, int i) {
    if (i == n) return;
    printf("a[%d] = ", i);
    scanf("%d", &a[i]);
    citire(a, n, i + 1);
}

void gasire_min_max(int a[], int n, int i, int *min, int *max) {
    if (i == n) return;
    if (a[i] < *min) *min = a[i];
    if (a[i] > *max) *max = a[i];
    gasire_min_max(a, n, i + 1, min, max);
}

int main() {
    int n;
    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);
    int a[n];
    citire(a, n, 0);
    int min = a[0], max = a[0];
    gasire_min_max(a, n, 0, &min, &max);

    printf("\nElementul minim este: %d", min);
    printf("\nElementul maxim este: %d\n", max);

    return 0;
}

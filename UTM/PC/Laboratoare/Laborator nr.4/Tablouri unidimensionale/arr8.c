// October 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.8: Scrieți un program C pentru a copia toate elementele dintr-un tablou în alt tablou.

#include <stdio.h>

int main() {
    int n;
    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Dimensiunea trebuie sa fie pozitiva!\n");
        return 0;
    }

    int a[n], b[n];

    printf("\nIntroduceti elementele tabloului initial:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }

    printf("\nElementele tabloului copiat sunt:\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    return 0;
}

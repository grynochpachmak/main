// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.15: Scrieți un program C pentru a îmbina două tablouri în al treilea tablou.

#include <stdio.h>

int main() {
    int n1, n2;

    printf("Introduceti dimensiunea primului tablou: ");
    scanf("%d", &n1);
    printf("Introduceti dimensiunea celui de-al doilea tablou: ");
    scanf("%d", &n2);

    if (n1 <= 0 || n2 <= 0) {
        printf("Dimensiunile trebuie sa fie pozitive!\n");
        return 0;
    }

    int a[n1], b[n2], c[n1 + n2];

    printf("\nIntroduceti elementele primului tablou:\n");
    for (int i = 0; i < n1; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("\nIntroduceti elementele celui de-al doilea tablou:\n");
    for (int i = 0; i < n2; i++) {
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n1; i++) {
        c[i] = a[i];
    }

    for (int i = 0; i < n2; i++) {
        c[n1 + i] = b[i];
    }

    printf("\nElementele celui de-al treilea tablou (imbinare):\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("c[%d] = %d\n", i, c[i]);
    }

    return 0;
}

// October 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.17: Scrieți un program C pentru a pune elemente pare și impare ale unui tablou în două tablouri separate.

#include <stdio.h>

int main() {
    int n;
    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Dimensiunea trebuie sa fie pozitiva!\n");
        return 0;
    }

    int a[n];
    printf("\nIntroduceti elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    int pare[n], impare[n];
    int p = 0, im = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            pare[p++] = a[i];
        else
            impare[im++] = a[i];
    }

    printf("\nElementele pare sunt:\n");
    if (p == 0)
        printf("(niciun element par)\n");
    else
        for (int i = 0; i < p; i++)
            printf("pare[%d] = %d\n", i, pare[i]);

    printf("\nElementele impare sunt:\n");
    if (im == 0)
        printf("(niciun element impar)\n");
    else
        for (int i = 0; i < im; i++)
            printf("impare[%d] = %d\n", i, impare[i]);

    return 0;
}

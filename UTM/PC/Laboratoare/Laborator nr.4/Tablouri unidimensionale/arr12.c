// October 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.12: Scrieți un program C pentru a imprima toate elementele unice din tablou.

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

    int unic;
    printf("\nElementele unice din tablou sunt:\n");

    for (int i = 0; i < n; i++) {
        unic = 1;

        for (int j = 0; j < n; j++) {
            if (i != j && a[i] == a[j]) {
                unic = 0;
                break;
            }
        }

        if (unic == 1)
            printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}

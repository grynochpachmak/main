// October 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.19: Scrieți un program C pentru a sorta elementele tabloului în ordine crescătoare sau descrescătoare.

#include <stdio.h>

int main() {
    int n, optiune;

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

    printf("\nAlegeti modul de sortare:\n");
    printf("1 - Ordine crescatoare\n");
    printf("2 - Ordine descrescatoare\n");
    printf("Optiunea dvs: ");
    scanf("%d", &optiune);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((optiune == 1 && a[i] > a[j]) || (optiune == 2 && a[i] < a[j])) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    if (optiune == 1)
        printf("\nTabloul sortat in ordine crescatoare:\n");
    else if (optiune == 2)
        printf("\nTabloul sortat in ordine descrescatoare:\n");
    else {
        printf("\nOptiune invalida!\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

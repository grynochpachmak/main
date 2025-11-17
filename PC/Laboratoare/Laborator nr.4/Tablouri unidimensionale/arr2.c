// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.2: Scrieți un program C pentru a imprima toate elementele negative dintr-un tablou.

#include <stdio.h>

int main() {
    int n;
    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);

    int a[n];
    printf("\nIntroduceti valorile tabloului:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            count++;
    }

    if (count == 0) {
        printf("\nNu aveti valori negative.\n");
        return 0;
    }

    printf("\nElementele negative din tablou sunt:\n");
    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

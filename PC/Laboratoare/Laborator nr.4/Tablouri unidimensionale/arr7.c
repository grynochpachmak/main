// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.7: Scrieți un program C pentru a număra numărul total de elemente negative dintr-un tablou.

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

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            count++;
    }

    printf("\nNumarul total de elemente negative: %d\n", count);

    return 0;
}

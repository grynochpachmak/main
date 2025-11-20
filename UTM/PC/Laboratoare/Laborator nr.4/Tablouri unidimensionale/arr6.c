// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.6: Scrieți un program C pentru a număra numărul total de elemente pare și impare dintr-un tablou.

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

    int pare = 0, impare = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            pare++;
        else
            impare++;
    }

    printf("\nNumarul total de elemente pare: %d", pare);
    printf("\nNumarul total de elemente impare: %d\n", impare);

    return 0;
}

// October 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.9: Scrieți un program C pentru a insera un element într-un tablou pe o poziție dată de la tastatură.

#include <stdio.h>

int main() {
    int n, pos, elem;

    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Dimensiunea trebuie sa fie pozitiva!\n");
        return 0;
    }

    int a[n + 1];

    printf("\nIntroduceti elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("\nIntroduceti valoarea elementului de inserat: ");
    scanf("%d", &elem);

    printf("Introduceti pozitia unde doriti sa inserati elementul (0 - %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Pozitie invalida!\n");
        return 0;
    }

    for (int i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = elem;
    n++;

    printf("\nTabloul dupa inserare:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

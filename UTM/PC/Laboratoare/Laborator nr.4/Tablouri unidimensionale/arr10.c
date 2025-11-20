// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.10: Scrieți un program C pentru a șterge un element dintr-un tablou în poziția specificată de la tastatură.

#include <stdio.h>

int main() {
    int n, pos;

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

    printf("\nIntroduceti pozitia elementului de sters (0 - %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Pozitie invalida!\n");
        return 0;
    }

    for (int i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n--;

    printf("\nTabloul dupa stergere:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

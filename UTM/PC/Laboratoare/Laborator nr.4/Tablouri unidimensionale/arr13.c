// October 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.13: Scrieți un program C pentru a număra numărul total de elemente duplicate dintr-un tablou.

#include <stdio.h>
#include <stdbool.h>

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

    bool vizitat[n];
    for (int i = 0; i < n; i++)
        vizitat[i] = false;

    int duplicate = 0;

    for (int i = 0; i < n; i++) {
        if (vizitat[i])
            continue;

        int contor = 1;

        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                contor++;
                vizitat[j] = true;
            }
        }

        if (contor > 1)
            duplicate++;
    }

    printf("\nNumarul total de elemente duplicate este: %d\n", duplicate);

    return 0;
}

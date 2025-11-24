// October 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.18: Scrieți un program C pentru a căuta un element din tablou și afiza pozițiile găsite.

#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, valoare;
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

    printf("\nIntroduceti valoarea de cautat: ");
    scanf("%d", &valoare);

    bool gasit = false;

    printf("\nElementul %d a fost gasit la pozitiile: ", valoare);
    for (int i = 0; i < n; i++) {
        if (a[i] == valoare) {
            printf("%d ", i);
            gasit = true;
        }
    }

    if (!gasit)
        printf("nu a fost gasit in tablou.");

    printf("\n");
    return 0;
}

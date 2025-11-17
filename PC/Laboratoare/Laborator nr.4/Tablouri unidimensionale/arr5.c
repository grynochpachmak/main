// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.5: Scrieți un program C pentru a găsi al doilea cel mai mare element dintr-un tablou.

#include <stdio.h>

int main() {
    int n;
    printf("Introduceti dimensiunea tabloului: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Tabloul trebuie sa contina cel putin doua elemente!\n");
        return 0;
    }

    int a[n], max[n];

    printf("\nIntroduceti elementele tabloului:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
        max[i] = a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (max[i] < max[j]) {
                int temp = max[i];
                max[i] = max[j];
                max[j] = temp;
            }
        }
    }

    printf("\nAl doilea cel mai mare element este: %d\n", max[1]);

    return 0;
}

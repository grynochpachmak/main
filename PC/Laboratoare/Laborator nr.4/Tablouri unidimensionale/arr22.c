// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.22: Scrieți un program C pentru a roti dreapta un tablou, operația ROR.

#include <stdio.h>

int main() {
    int n, k;

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

    printf("\nIntroduceti numarul de pozitii pentru rotirea la dreapta (ROR): ");
    scanf("%d", &k);

    // normalise
    k = k % n;

    printf("\nTabloul initial:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    for (int r = 0; r < k; r++) {
        int temp = a[n - 1];
        for (int i = n - 1; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = temp;
    }

    printf("\n\nTabloul dupa rotirea la dreapta cu %d pozitii:\n", k);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}

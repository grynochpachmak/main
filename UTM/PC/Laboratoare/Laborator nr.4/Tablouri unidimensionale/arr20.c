// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.20: Scrieți un program C pentru a sorta separat elementele pare și impare ale tabloului.

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

    int pare[n], impare[n];
    int p = 0, im = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            pare[p++] = a[i];
        else
            impare[im++] = a[i];
    }

    for (int i = 0; i < p - 1; i++) {
        for (int j = i + 1; j < p; j++) {
            if (pare[i] > pare[j]) {
                int temp = pare[i];
                pare[i] = pare[j];
                pare[j] = temp;
            }
        }
    }

    for (int i = 0; i < im - 1; i++) {
        for (int j = i + 1; j < im; j++) {
            if (impare[i] > impare[j]) {
                int temp = impare[i];
                impare[i] = impare[j];
                impare[j] = temp;
            }
        }
    }

    int k = 0;
    for (int i = 0; i < p; i++)
        a[k++] = pare[i];
    for (int i = 0; i < im; i++)
        a[k++] = impare[i];

    printf("\nTabloul dupa sortarea separata a elementelor pare si impare:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}

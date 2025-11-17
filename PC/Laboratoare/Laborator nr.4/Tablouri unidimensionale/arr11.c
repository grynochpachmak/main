// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri unidimensionale
// Sarcina nr.11: Scrieți un program C pentru a număra frecvența relativă fiecărui element dintr-un tablou.

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

    int vizitat[n];
    for (int i = 0; i < n; i++)
        vizitat[i] = 0;

    printf("\nElement | Frecventa absoluta | Frecventa relativa\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (vizitat[i] == 1)
            continue;

        int contor = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                contor++;
                vizitat[j] = 1;
            }
        }

        float frecv_relativa = (float)contor / n;
        printf("%7d | %18d | %17.0f%%\n", a[i], contor, frecv_relativa * 100);
    }

    return 0;
}

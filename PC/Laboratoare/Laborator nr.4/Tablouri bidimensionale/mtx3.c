// November 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri bidimensionale
// Sarcina nr.3: Scrieti un program C pentru a efectua multiplicarea matricei cu un scalar.

#include <stdio.h>

int main() {
    int n, m, k;

    printf("Introduceti numarul de linii: ");
    scanf("%d", &n);
    printf("Introduceti numarul de coloane: ");
    scanf("%d", &m);

    printf("Introduceti scalarul k: ");
    scanf("%d", &k);

    int A[n][m], R[n][m];

    printf("\nIntroduceti elementele matricei A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            R[i][j] = A[i][j] * k;
        }
    }

    printf("\nMatricea rezultata R = k * A este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// November 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri bidimensionale
// Sarcina nr.1: Scrieti un program C pentru a aduna doua matrice.

#include <stdio.h>

int main() {
    int n, m;

    printf("Introduceti numarul de linii: ");
    scanf("%d", &n);
    printf("Introduceti numarul de coloane: ");
    scanf("%d", &m);

    int A[n][m], B[n][m], S[n][m];

    printf("\nIntroduceti elementele matricei A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nIntroduceti elementele matricei B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            S[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nSuma matricelor S = A + B este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", S[i][j]);
        }
        printf("\n");
    }

    return 0;
}
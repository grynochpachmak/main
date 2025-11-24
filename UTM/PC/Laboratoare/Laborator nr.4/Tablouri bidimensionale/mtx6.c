// November 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri bidimensionale
// Sarcina nr.6: Scrieti un program C pentru a gasi suma elementelor diagonalei principale ale unei matrici.

#include <stdio.h>

int main() {
    int n;

    printf("Introduceti dimensiunea matricii patrate n: ");
    scanf("%d", &n);

    int A[n][n];
    int suma = 0;

    printf("\nIntroduceti elementele matricii A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Suma diagonalei principale
    for (int i = 0; i < n; i++) {
        suma += A[i][i];
    }

    printf("\nSuma elementelor diagonalei principale este: %d\n", suma);

    return 0;
}

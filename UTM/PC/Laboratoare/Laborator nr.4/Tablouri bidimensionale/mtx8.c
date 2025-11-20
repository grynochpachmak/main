// November 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri bidimensionale
// Sarcina nr.8: Scrieti un program C pentru a gasi suma fiecarui rand si coloana a unei matrici.

#include <stdio.h>

int main() {
    int n, m;

    printf("Introduceti numarul de linii: ");
    scanf("%d", &n);
    printf("Introduceti numarul de coloane: ");
    scanf("%d", &m);

    int A[n][m];

    printf("\nIntroduceti elementele matricei A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nSuma fiecarui rand:\n");
    for (int i = 0; i < n; i++) {
        int sumaRand = 0;
        for (int j = 0; j < m; j++) {
            sumaRand += A[i][j];
        }
        printf("Randul %d: %d\n", i, sumaRand);
    }

    printf("\nSuma fiecarei coloane:\n");
    for (int j = 0; j < m; j++) {
        int sumaColoana = 0;
        for (int i = 0; i < n; i++) {
            sumaColoana += A[i][j];
        }
        printf("Coloana %d: %d\n", j, sumaColoana);
    }

    return 0;
}

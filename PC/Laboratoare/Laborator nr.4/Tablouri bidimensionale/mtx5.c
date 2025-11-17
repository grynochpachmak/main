// November 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri bidimensionale
// Sarcina nr.5: Scrieti un program C pentru a verifica daca doua matrice sunt egale sau nu.

#include <stdio.h>

int main() {
    int n, m;

    printf("Introduceti numarul de linii: ");
    scanf("%d", &n);
    printf("Introduceti numarul de coloane: ");
    scanf("%d", &m);

    int A[n][m], B[n][m];

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

    int egale = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                egale = 0;
                break;
            }
        }
        if (!egale)
            break;
    }

    if (egale)
        printf("\nMatricele sunt egale.\n");
    else
        printf("\nMatricele NU sunt egale.\n");

    return 0;
}

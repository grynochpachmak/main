// November 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri bidimensionale
// Sarcina nr.4: Scrieti un program C pentru a multiplica doua matrice.

#include <stdio.h>

int main() {
    int n1, m1;
    int n2, m2;

    printf("Introduceti numarul de linii pentru matricea A: ");
    scanf("%d", &n1);
    printf("Introduceti numarul de coloane pentru matricea A: ");
    scanf("%d", &m1);

    printf("Introduceti numarul de linii pentru matricea B: ");
    scanf("%d", &n2);
    printf("Introduceti numarul de coloane pentru matricea B: ");
    scanf("%d", &m2);

    if (m1 != n2) {
        printf("\nMultiplicarea nu este posibila. Numărul coloanelor din A trebuie sa fie egal cu numărul liniilor din B.\n");
        return 1;
    }

    int A[n1][m1], B[n2][m2], C[n1][m2];

    printf("\nIntroduceti elementele matricei A:\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nIntroduceti elementele matricei B:\n");
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nRezultatul multiplicarii C = A * B este:\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

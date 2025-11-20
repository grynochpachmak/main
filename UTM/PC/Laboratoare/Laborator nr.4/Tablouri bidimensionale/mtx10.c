// November 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri bidimensionale
// Sarcina nr.10: Scrieti un program C pentru a sterge un element dintr-o matrice in pozitia specificata de la tastatura.

#include <stdio.h>

int main() {
    int n, m;

    printf("Introduceti numarul de linii: ");
    scanf("%d", &n);
    printf("Introduceti numarul de coloane: ");
    scanf("%d", &m);

    int A[100][100];

    printf("\nIntroduceti elementele matricii A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int lin, col;
    printf("\nIntroduceti pozitia elementului de sters (linie 0-%d, coloana 0-%d): ", n - 1, m - 1);
    scanf("%d %d", &lin, &col);

    if (lin < 0 || lin >= n || col < 0 || col >= m) {
        printf("\nPozitie invalida!\n");
        return 1;
    }

    // 2d->1d
    int poz = lin * m + col;

    int total = n * m;

    // 2left
    for (int k = poz; k < total - 1; k++) {
        int i = k / m;
        int j = k % m;

        int inext = (k + 1) / m;
        int jnext = (k + 1) % m;

        A[i][j] = A[inext][jnext];
    }

    total--; // normalise

    printf("\nMatricea dupa stergere este:\n");
    for (int i = 0; i < (total + m - 1) / m; i++) {
        for (int j = 0; j < m; j++) {
            if (i * m + j < total)
                printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}

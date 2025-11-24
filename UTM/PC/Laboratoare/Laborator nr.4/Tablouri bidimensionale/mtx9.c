// November 2025
// Juncu Marin MN-251
// Laborator nr.4: Prelucrarea tablourilor unidimensionale si bidimensionale în limbajul C
// Tablouri bidimensionale
// Sarcina nr.9: Scrieti un program C pentru a insera un element intr-o matrice pe o pozitie data de la tastatura.

#include <stdio.h>

int main() {
    int n, m;

    printf("Introduceti numarul de linii: ");
    scanf("%d", &n);
    printf("Introduceti numarul de coloane: ");
    scanf("%d", &m);

    int A[100][100];  // max len

    printf("\nIntroduceti elementele matricii A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    int elem, lin, col;
    printf("\nIntroduceti elementul de inserat: ");
    scanf("%d", &elem);

    printf("Introduceti pozitia (linie intre 0-%d, coloana intre 0-%d): ", n-1, m-1);
    scanf("%d %d", &lin, &col);

    if (lin < 0 || lin >= n || col < 0 || col >= m) {
        printf("\nPozitie invalida!\n");
        return 1;
    }

    // 2d->1d
    int poz = lin * m + col;

    int total = n * m;

    // 2right
    for (int k = total; k > poz; k--) {
        int i = k / m;
        int j = k % m;
        int ip = (k - 1) / m;
        int jp = (k - 1) % m;

        A[i][j] = A[ip][jp];
    }

    // 4print
    A[lin][col] = elem;

    // normalise
    total++;

    printf("\nMatricea dupa inserare este:\n");
    for (int i = 0; i < (total + m - 1) / m; i++) {
        for (int j = 0; j < m; j++) {
            if (i * m + j < total)
                printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}

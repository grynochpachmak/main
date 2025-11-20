#include <stdio.h>

#define MAX_SIZE 100  // Dimensiunea maxima a matricei

// Functia care calculeaza maximul dintre sumele elementelor negative de pe diagonale
int maxim_suma_negative_diagonale(int matrice[MAX_SIZE][MAX_SIZE], int n) {
    int suma_diagonala_principala = 0;
    int suma_diagonala_secundara = 0;

    // Calcularea sumelor pentru diagonala principala si secundara
    for (int i = 0; i < n; i++) {
        // Diagonala principala: A[i][i]
        if (matrice[i][i] < 0) {
            suma_diagonala_principala += matrice[i][i];
        }
        // Diagonala secundara: A[i][n-i-1]
        if (matrice[i][n - i - 1] < 0) {
            suma_diagonala_secundara += matrice[i][n - i - 1];
        }
    }

    // Determinarea maximului dintre cele doua sume
    return (suma_diagonala_principala > suma_diagonala_secundara) ? suma_diagonala_principala : suma_diagonala_secundara;
}

int main() {
    int n;

    // Citirea dimensiunii matricei
    printf("Introduceti dimensiunea matricei (n x n): ");
    scanf("%d", &n);

    // Declararea matricei
    int matrice[MAX_SIZE][MAX_SIZE];

    // Citirea elementelor matricei
    printf("Introduceti elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    // Apelarea functiei pentru a calcula maximul
    int rezultat = maxim_suma_negative_diagonale(matrice, n);

    // Afisarea rezultatului
    printf("Maximul dintre sumele elementelor negative de pe diagonale este: %d\n", rezultat);

    return 0;
}

// October 2025
// Juncu Marin MN-251
// Laborator nr.3: Prelucrarea tablourilor bidimensionale în limbajul C
// Sarcina: Să se determine maximul dintre sumele elementelor negative de pe diagonala principală și cea secundară.

#include <stdio.h>

int main() {
    int n, m, select;

    while(1) {

        printf("Alegeti metoda de generare a matricei (1 - automat; 2 - de la tastiera): ");
        scanf("%d", &select);

        if(select != 1 && select != 2) {
            printf("Introduceti 1 sau 2!\n\n");
            continue;
        }

        break;
    }

    while(1) {

        printf("\nDati dimensiune matricei:\n");
        printf("Linii: ");
        scanf("%d", &n);
        printf("Coloane: ");
        scanf("%d", &m);

        if(n <=0 || m <= 0) {
            printf("\nDimensiunile nu pot fi negative!\n");
            continue;
        }

        if(n != m) {
            printf("\nAvertisment: Matricea nu este patratica. Diagonalele vor fi calculate pana la dimensiunea minima.\n\n");
        }

        break;
    }

    int a[n][m];
 
        switch(select) {
        
            case 1:
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        a[i][j] = -(i + j);
                    }
                }
                break;

            case 2:
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        do {
                            printf("a[%d][%d] = ", i, j);
                            scanf("%d", &a[i][j]);
                            if(a[i][j] > 0)
                                printf("\nDatele trebuie sa fie negative! Reintroduceti valoarea.\n\n");
                        } while (a[i][j] > 0);
                    }
                }
                break;

        }

    printf("\nMatricea:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    int sdp = 0; // Suma Diagonalei Principale
    for(int i = 0; i < n && i < m; i++) {
        sdp += a[i][i];
    }

    int sds = 0; // Suma Diagonalei Secundare
    for(int i = 0; i < n && i < m; i++) {
        sds += a[i][m - i - 1];
    }

    printf("\n");
    printf("Suma Diagonalei Principale (SDP): %d\n", sdp);
    printf("Suma Diagonalei Secundare (SDS):  %d\n", sds);

    if(sdp == sds) 
        printf("Sumele diagonalelor sunt egale.");
    else if(sdp < sds)
            printf("SDP este mai mare ca SDS cu %d (ca modul).", -(sdp - sds));
    else
        printf("SDS este mai mare ca SDP cu %d (ca modul).", -(sds - sdp));

    return 0;
}
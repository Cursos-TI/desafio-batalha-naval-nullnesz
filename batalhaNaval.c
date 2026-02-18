#include <stdio.h>

int main() {

    int tabuleiro[10][10];
    int TAM = 10;
    int TAM_NAVIO = 3;

    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;

    int linhaH = 0, colunaH = 1;
    int linhaV = 7, colunaV = 0;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaH][colunaH + i] = 3;

    for (int i = 0; i < TAM_NAVIO; i++)
        tabuleiro[linhaV + i][colunaV] = 3;

    int cruz[5][5] = {
        {0,0,3,0,0},
        {0,0,3,0,0},
        {3,3,3,3,3},
        {0,0,3,0,0},
        {0,0,3,0,0}
    };

    int octaedro[5][5] = {
        {0,0,0,0,0},
        {0,0,3,0,0},
        {0,3,3,3,0},
        {0,0,3,0,0},
        {0,0,0,0,0}
    };

    int cone[5][5] = {
        {0,0,0,0,0},
        {0,0,3,0,0},
        {0,3,3,3,0},
        {3,3,3,3,3},
        {0,0,0,0,0}
    };

    int centros[3][2] = {
        {2,7},
        {5,5},
        {8,6}
    };

    int (*habilidades[3])[5] = {cruz, octaedro, cone};
    int marcadores[3] = {5, 6, 7};

    for (int h = 0; h < 3; h++) {

        int centroLinha = centros[h][0];
        int centroColuna = centros[h][1];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                if (habilidades[h][i][j] == 3) {

                    int linhaTab = centroLinha - 2 + i;
                    int colunaTab = centroColuna - 2 + j;

                    if (linhaTab >= 0 && linhaTab < TAM &&
                        colunaTab >= 0 && colunaTab < TAM) {

                        if (tabuleiro[linhaTab][colunaTab] == 0)
                            tabuleiro[linhaTab][colunaTab] = marcadores[h];
                    }
                }
            }
        }
    }

    printf("\n===== TABULEIRO FINAL =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++)
            printf("%d ", tabuleiro[i][j]);
        printf("\n");
    }

    return 0;
}

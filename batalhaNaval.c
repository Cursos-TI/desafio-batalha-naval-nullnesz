#include <stdio.h>

int main() {
     
    int tabuleiro[10][10];
    int TAM = 10;
    int TAM_NAVIO = 3;

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int linhaH = 2, colunaH = 3;
    int linhaV = 6, colunaV = 1;

    int linhaD1 = 0, colunaD1 = 0;   // diagonal principal
    int linhaD2 = 0, colunaD2 = 9;   // diagonal secundária

    // Horizontal
    if (colunaH + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaH][colunaH + i] = 3;
        }
    }

    // Vertical
    if (linhaV + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaV + i][colunaV] = 3;
        }
    }

    // Diagonal principal (linha e coluna aumentam juntos)
    if (linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM) {
        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
        }
    }

    // Diagonal secundária (linha aumenta, coluna diminui)
    if (linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {
        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0)
                sobreposicao = 1;
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++)
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
        }
    }

    printf("\n===== TABULEIRO COMPLETO =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

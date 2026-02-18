#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
     
    // 1. Declaração da matriz 10x10
    
    int tabuleiro[10][10];
    int TAM = 10;
    int TAM_NAVIO = 3;

    // Inicializa toda a matriz com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    
    // 2. Coordenadas iniciais dos navios
    
    int linhaH = 2, colunaH = 3; // Navio horizontal
    int linhaV = 6, colunaV = 1; // Navio vertical

    
    // 3. Posicionamento do navio horizontal
    

    if (colunaH + TAM_NAVIO <= TAM) {

        int sobreposicao = 0;

        // Verifica sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                sobreposicao = 1;
            }
        }

        // Se não houver sobreposição, marca com 3
        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        } else {
            printf("Erro: Sobreposição no navio horizontal.\n");
        }

    } else {
        printf("Erro: Navio horizontal fora do tabuleiro.\n");
    }

    
    // 4. Posicionamento do navio vertical
    

    if (linhaV + TAM_NAVIO <= TAM) {

        int sobreposicao = 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        } else {
            printf("Erro: Sobreposição no navio vertical.\n");
        }

    } else {
        printf("Erro: Navio vertical fora do tabuleiro.\n");
    }

    
    // 5. Exibição do tabuleiro
    

    printf("\n===== TABULEIRO =====\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

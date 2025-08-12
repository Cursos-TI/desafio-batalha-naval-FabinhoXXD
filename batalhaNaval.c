#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para imprimir o tabuleiro formatado
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        printf("%2d ", i); // Cabeçalho de colunas
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i); // Índice de linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se é possível posicionar um navio no tabuleiro
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        switch (orientacao) {
            case 0: c += i; break;             // Horizontal direita
            case 1: l += i; break;             // Vertical para baixo
            case 2: l += i; c += i; break;     // Diagonal ↘
            case 3: l += i; c -= i; break;     // Diagonal ↙
            default: return 0;
        }

        // Fora dos limites
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return 0;

        // Já tem navio na posição
        if (tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

// Posiciona um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        switch (orientacao) {
            case 0: c += i; break;             // Horizontal
            case 1: l += i; break;             // Vertical
            case 2: l += i; c += i; break;     // Diagonal ↘
            case 3: l += i; c -= i; break;     // Diagonal ↙
        }

        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // ----------- NAVIOS DEFINIDOS MANUALMENTE ----------------

    // Navio 1 - Horizontal: linha 0, coluna 2
    int linha1 = 0, coluna1 = 2, orientacao1 = 0;

    // Navio 2 - Vertical: linha 3, coluna 5
    int linha2 = 3, coluna2 = 5, orientacao2 = 1;

    // Navio 3 - Diagonal ↘: linha 6, coluna 6
    int linha3 = 6, coluna3 = 6, orientacao3 = 2;

    // Navio 4 - Diagonal ↙: linha 1, coluna 4
    int linha4 = 1, coluna4 = 4, orientacao4 = 3;

    // Posiciona os navios com validação
    if (podePosicionarNavio(tabuleiro, linha1, coluna1, orientacao1))
        posicionarNavio(tabuleiro, linha1, coluna1, orientacao1);
    else
        printf("Erro ao posicionar navio 1 (horizontal).\n");

    if (podePosicionarNavio(tabuleiro, linha2, coluna2, orientacao2))
        posicionarNavio(tabuleiro, linha2, coluna2, orientacao2);
    else
        printf("Erro ao posicionar navio 2 (vertical).\n");

    if (podePosicionarNavio(tabuleiro, linha3, coluna3, orientacao3))
        posicionarNavio(tabuleiro, linha3, coluna3, orientacao3);
    else
        printf("Erro ao posicionar navio 3 (diagonal ↘).\n");

    if (podePosicionarNavio(tabuleiro, linha4, coluna4, orientacao4))
        posicionarNavio(tabuleiro, linha4, coluna4, orientacao4);
    else
        printf("Erro ao posicionar navio 4 (diagonal ↙).\n");

    // Exibe o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
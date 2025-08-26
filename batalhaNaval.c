#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Imprime o tabuleiro com cabeçalhos de linha e coluna
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
        printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se é possível posicionar um navio sem ultrapassar os limites
// e sem colidir com outros navios
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        // Define a direção do navio
        switch (orientacao) {
            case 0: c += i; break; // horizontal
            case 1: l += i; break; // vertical
            case 2: l += i; c += i; break; // diagonal 
            case 3: l += i; c -= i; break; // diagonal 
            default: return 0;
        }

        // Verifica se a posição está dentro dos limites
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return 0;

        // Verifica se a posição já está ocupada
        if (tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

// Marca o navio na matriz
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                     int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        switch (orientacao) {
            case 0: c += i; break;
            case 1: l += i; break;
            case 2: l += i; c += i; break;
            case 3: l += i; c -= i; break;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Navio horizontal
    int linha1 = 0, coluna1 = 2, orientacao1 = 0;

    // Navio vertical
    int linha2 = 3, coluna2 = 5, orientacao2 = 1;

    // Navio diagonal 
    int linha3 = 6, coluna3 = 6, orientacao3 = 2;

    // Navio diagonal 
    int linha4 = 1, coluna4 = 4, orientacao4 = 3;

    // Tenta posicionar os navios, um por um
    if (podePosicionarNavio(tabuleiro, linha1, coluna1, orientacao1))
        posicionarNavio(tabuleiro, linha1, coluna1, orientacao1);

    if (podePosicionarNavio(tabuleiro, linha2, coluna2, orientacao2))
        posicionarNavio(tabuleiro, linha2, coluna2, orientacao2);

    if (podePosicionarNavio(tabuleiro, linha3, coluna3, orientacao3))
        posicionarNavio(tabuleiro, linha3, coluna3, orientacao3);

    if (podePosicionarNavio(tabuleiro, linha4, coluna4, orientacao4))
        posicionarNavio(tabuleiro, linha4, coluna4, orientacao4);

    // Exibe o resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
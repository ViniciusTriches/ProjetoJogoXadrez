#include <stdio.h>
#include <stdlib.h>
#include "PosicaoTabuleiro.cpp"

Posicao* criarPosicao(int Linha, int Coluna) {
    Posicao* novaPosicao = (Posicao*)malloc(sizeof(Posicao));
    if (!novaPosicao) {
        printf("Erro ao alocar memória para a posição.\n");
        exit(1);
    }
    novaPosicao->linha = Linha;
    novaPosicao->coluna = Coluna;
    return novaPosicao;
}

void definirValores(Posicao* posicao, int linha, int coluna) {
    if (posicao) {
        posicao->linha = linha;
        posicao->coluna = coluna;
    }
}

void posicaoToString(Posicao* posicao, char* buffer, size_t bufferSize) {
    if (posicao && buffer) {
        snprintf(buffer, bufferSize, "%d, %d", posicao->linha, posicao->coluna);
    }
}
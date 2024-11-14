#include <stdio.h>
#include "PosicaoTabuleiro.cpp"

typedef struct {
    char coluna;
    int linha;
} PosicaoXadrez;

PosicaoXadrez criarPosicaoXadrez(char coluna, int linha) {
    PosicaoXadrez novaPosicaoXadrez;
    novaPosicaoXadrez.coluna = coluna;
    novaPosicaoXadrez.linha = linha;
    return novaPosicaoXadrez;
}

Posicao toPosicao(PosicaoXadrez posXadrez) {
    Posicao pos;
    pos.linha = 8 - posXadrez.linha;
    pos.coluna = posXadrez.coluna - 'a';
    return pos;
}

void posicaoXadrezToString(PosicaoXadrez posXadrez, char* buffer, size_t bufferSize) {
    snprintf(buffer, bufferSize, "%c%d", posXadrez.coluna, posXadrez.linha);
}
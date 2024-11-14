#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Peca.cpp"
#include "Posicao.cpp"

typedef struct {
    int linhas;
    int colunas;
    Peca*** pecas;
} Tabuleiro;

Tabuleiro* criarTabuleiro(int linhas, int colunas) {
    Tabuleiro* tab = (Tabuleiro*)malloc(sizeof(Tabuleiro));
    if (!tab) {
        printf("Erro ao alocar memória para o tabuleiro.\n");
        exit(1);
    }

    tab->linhas = linhas;
    tab->colunas = colunas;

    tab->pecas = (Peca***)malloc(linhas * sizeof(Peca**));
    for (int i = 0; i < linhas; i++) {
        tab->pecas[i] = (Peca**)calloc(colunas, sizeof(Peca*));
    }

    return tab;
}

Peca* acessarPeca(Tabuleiro* tab, int linha, int coluna) {
    if (!tab || linha < 0 || linha >= tab->linhas || coluna < 0 || coluna >= tab->colunas) {
        return NULL;
    }
    return tab->pecas[linha][coluna];
}

Peca* acessarPecaPorPosicao(Tabuleiro* tab, Posicao* pos) {
    return acessarPeca(tab, pos->linha, pos->coluna);
}

bool existePeca(Tabuleiro* tab, Posicao* pos) {
    return acessarPecaPorPosicao(tab, pos) != NULL;
}

void colocarPeca(Tabuleiro* tab, Peca* p, Posicao* pos) {
    if (existePeca(tab, pos)) {
        printf("Erro: já existe uma peça nessa posição!\n");
        return;
    }
    tab->pecas[pos->linha][pos->coluna] = p;
    p->posicao = pos;
}

Peca* retirarPeca(Tabuleiro* tab, Posicao* pos) {
    Peca* p = acessarPecaPorPosicao(tab, pos);
    if (p) {
        tab->pecas[pos->linha][pos->coluna] = NULL;
        p->posicao = NULL;
    }
    return p;
}

bool posicaoValida(Tabuleiro* tab, Posicao* pos) {
    return pos->linha >= 0 && pos->linha < tab->linhas && pos->coluna >= 0 && pos->coluna < tab->colunas;
}

void validarPosicao(Tabuleiro* tab, Posicao* pos) {
    if (!posicaoValida(tab, pos)) {
        printf("Erro: posição inválida!\n");
        exit(1);
    }
}

void liberarTabuleiro(Tabuleiro* tab) {
    if (!tab) return;

    for (int i = 0; i < tab->linhas; i++) {
        free(tab->pecas[i]);
    }
    free(tab->pecas);
    free(tab);
}
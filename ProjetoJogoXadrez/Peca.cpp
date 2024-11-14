#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Cor.cpp"

#define MAX_LINHAS 8
#define MAX_COLUNAS 8

typedef struct Posicao {
    int linha;
    int coluna;
};

typedef struct  Tabuleiro{
    int linhas;
    int colunas;
};

typedef struct Peca {
    Posicao* posicao;
    Cor cor;
    int qteMovimentos;
    Tabuleiro* tab;

    bool** (*movimentosPossiveis)(struct Peca*);
    bool (*movimentoPossivel)(struct Peca*, Posicao);
    bool (*existeMovimentosPossiveis)(struct Peca*);
};

Peca* criarPeca(Tabuleiro* tab, Cor cor) {
    Peca* novaPeca = (Peca*)malloc(sizeof(Peca));
    if (!novaPeca) {
        printf("Erro ao alocar memória para a peça.\n");
        exit(1);
    }

    novaPeca->posicao = NULL;
    novaPeca->cor = cor;
    novaPeca->qteMovimentos = 0;
    novaPeca->tab = tab;

    novaPeca->movimentosPossiveis = NULL;
    novaPeca->movimentoPossivel = NULL;
    novaPeca->existeMovimentosPossiveis = NULL;

    return novaPeca;
}

void incrementarQteMovimentos(Peca* peca) {
    if (peca) {
        peca->qteMovimentos++;
    }
}

void decrementarQteMovimentos(Peca* peca) {
    if (peca && peca->qteMovimentos > 0) {
        peca->qteMovimentos--;
    }
}

bool exemploExisteMovimentosPossiveis(Peca* peca) {
    if (!peca || !peca->tab) return false;

    bool** mat = (bool**)malloc(peca->tab->linhas * sizeof(bool*));
    for (int i = 0; i < peca->tab->linhas; i++) {
        mat[i] = (bool*)malloc(peca->tab->colunas * sizeof(bool));
        for (int j = 0; j < peca->tab->colunas; j++) {
            mat[i][j] = false;
        }
    }

    for (int i = 0; i < peca->tab->linhas; i++) {
        free(mat[i]);
    }
    free(mat);

    return false;
}
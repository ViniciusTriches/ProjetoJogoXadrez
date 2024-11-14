#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para tratar exceções de tabuleiro
void tabuleiroException(const char* msg) {
    if (msg) {
        fprintf(stderr, "Erro: %s\n", msg);
    }
    exit(EXIT_FAILURE);
}
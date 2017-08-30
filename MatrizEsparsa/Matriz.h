#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include "Celula.h"

struct Matriz
{
    Celula* celula;
    int linhas;
    int colunas;

    void inicializar(Matriz* matriz, int linha, int coluna);
    bool AtribuiMatriz(Matriz* matriz, int linha, int coluna, float valor);
    float ValorMatriz(Matriz* matriz, int linha, int coluna);
};

#endif // MATRIZ_H_INCLUDED

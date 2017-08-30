#include "Matriz.h"

void Matriz::inicializar(Matriz* matriz, int linha, int coluna)
{
    int i;
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    m->celula = new Celula();
    //  m->celula = (Celula*) malloc(linha*sizeof(Celula));
    for (i = 0, i<linha, i++)
    {
        m->celula[i] = NULL;
    }
}

bool Matriz::AtribuiMatriz(Matriz* matriz, int linha, int coluna, float valor)
{

    if (linha < 0 ||linha >= matriz->linhas || coluna <0 || coluna >= matriz-> colunas)
        return false;

    Celula antes = NULL;
    Celula atual = matriz->celula[linha];
    while(atual != NULL && atual->coluna < coluna)
    {
        antes = atual;
        atual = atual->prox;
    }
}

float Matriz::ValorMatriz(Matriz* matriz, int linha, int coluna)
{
    if (linha <0 || linha >= matriz->linhas || coluna<0 || coluna >= matriz->colunas)
        return 0;

    Celula atual = matriz->celula[linha];
    while(atual != NULL && atual->coluna < coluna)
        atual = atual->prox;
    if (atual != NULL && atual->coluna == coluna)
        return atual->valor;
    return 0;
}

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Celula.h"
struct Lista
{
    Celula* primeiro;
    int Linha, Coluna;
    void inicializar(int linha, int coluna);
    void inserir(int linha, int coluna, float valor);
    void inserirAoFinal(int elemento);
    void inserirNoInicio(int elemento);
    bool vazia();
    void imprimirBase();
    void imprimirValor();
    void imprimirMatriz();
};
#endif // LISTA_H_INCLUDED

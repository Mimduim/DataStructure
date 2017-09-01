#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include "Lista.h"
struct Matriz{
    Lista lista;
    Matriz somaMatriz(Matriz A, Matriz B);
    Matriz multiplicaMatriz(Matriz A, Matriz B);
    void inicialize(int linha, int coluna);
    void leMatriz(int linha, int coluna, float valor);
    void imprimeMatriz();
    void removeElemento(int linha, int coluna);
    void  calculoEconomiaBytes();
};


#endif // MATRIZ_H_INCLUDED

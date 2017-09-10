/*
Aluno: Paulo Henrique Rodrigues da Cunha Santos
Nº: 0022012
Disciplina: Algoritmos e Estruturas de Dados 2
Trabalho Pratico 1
data: 03/09/2017
hora: 01:00
*/
#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include "Lista.h"
struct Matriz{
    Lista lista;
    Matriz somaMatriz(Matriz *A, Matriz *B);
    Matriz multiplicaMatriz(Matriz *A, Matriz *B);
    void inicialize(int linha, int coluna);
    void leMatriz(int linha, int coluna, float valor);
    void imprimeMatriz();
    void removeElemento(int linha, int coluna);
    void calculoEconomiaBytes();
    bool verificaSoma(Matriz *A, Matriz *B);
    bool verificaMulti(Matriz *A, Matriz *B);
};
#endif // MATRIZ_H_INCLUDED

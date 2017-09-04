/*
Aluno: Paulo Henrique Rodrigues da Cunha Santos
Nº: 0022012
Disciplina: Algoritmos e Estruturas de Dados 2
Trabalho Pratico 1
data: 03/09/2017
hora: 01:00
*/
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Celula.h"
struct Lista
{
    Celula* primeiro;
    int Linha, Coluna;
    void inicializar(int linha, int coluna);
    void inserir(int linha, int coluna, float valor);
    void imprimirBase();
    void imprimirValor();
    void imprimirMatriz();
    void economia();
    void remover(int linha, int coluna);
    Lista soma(Lista listaA, Lista listaB);
    Lista multi(Lista listaA, Lista listaB);
};
#endif // LISTA_H_INCLUDED

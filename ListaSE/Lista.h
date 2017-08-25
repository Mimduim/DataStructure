#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Celula.h"
struct Lista
{
    Celula* primeiro;
    bool vazia();
    void inicializar();
    void inserirAoFinal(Celula* c);
    void inserirNoInicio(Celula* c);
    Celula* pesquisar(int v);
    bool removerInicio();
    bool removerFinal();
    void imprimir();
};
#endif // LISTA_H_INCLUDED

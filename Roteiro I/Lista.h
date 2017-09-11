#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Celula.h"
struct Lista
{
    Celula* primeiro;
    Celula* pesquisar(int v);
    Lista unirListaOrdem (Lista lista);
    Lista intersecLista (Lista lista);
    Lista ordenarLista (Lista lista);
    Lista intercalarListas (Lista lista);
    void inicializar();
    void removeElemento (int elemento);
    bool removerInicio();
    int nElementos();
    bool vazia();

    void inserirAoFinal(int elemento);
    void inserirNoInicio(int elemento);
    Lista unirLista(Lista lista);
    void clearList();
    bool existeElemento(int elemento);


    bool removerFinal();
    void insereOrdem(int elemento);
    void imprimir();
};
#endif // LISTA_H_INCLUDED

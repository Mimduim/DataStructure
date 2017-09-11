#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Celula.h"
struct Lista
{
    Celula* primeiro;
    Celula* pesquisar(int v);
    Lista unirListaOrdem (Lista lista);
    Lista intersecLista (Lista lista);

    void nElementos();
    void inicializar();
    void inserirAoFinal(int elemento);
    void inserirNoInicio(int elemento);
    void unirLista(Lista lista);
    void clearList();
    bool existeElemento(int elemento);
    bool vazia();
    void removeElemento (int elemento);
    bool removerInicio();
    bool removerFinal();
    void insereOrdem(int elemento);
    void imprimir();
};
#endif // LISTA_H_INCLUDED

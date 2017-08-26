#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED
#include "CelulaString.h"
struct ListaString
{
    CelulaString* primeiro;
    void inicializar();
    void inserirAoFinal(std::string palavra);
    void inserirNoInicio(std::string palavra);
    bool vazia();
    void imprimir();
};


#endif // LISTASTRING_H_INCLUDED

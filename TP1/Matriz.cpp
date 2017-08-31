#include "Matriz.h"
#include "Lista.cpp"

void Matriz::inicialize(int linha, int coluna)
{
    lista.inicializar(linha,coluna);
}
void Matriz::leMatriz(int linha, int coluna, float valor)
{
    lista.inserir(linha,coluna,valor);
}

void Matriz::imprimeMatriz()
{
    lista.imprimirMatriz();
}

Matriz Matriz::somaMatriz(Matriz A, Matriz B)
{
    Matriz C;
    C.lista = A.lista.soma(A.lista,B.lista);
    return C;
}

Matriz Matriz::multiplicaMatriz(Matriz A, Matriz B)
{
    Matriz C;
    C.lista = A.lista.multi(A.lista,B.lista);
    return C;
}

void Matriz::calculoEconomiaBytes(Matriz matriz){
    matriz.lista.economia();
}

void Matriz::removeElemento(int linha, int coluna, Matriz matriz){
    matriz.lista.remover(linha,coluna);
}


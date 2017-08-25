#include <iostream>
#include "Lista.cpp"
using namespace std;

int main()
{

    Lista numeros; //primeiro = NULL
    numeros.inicializar();
    Celula* n = new Celula(); // valor = 0, prox =NULL
    n->valor = 10;
    numeros.inserirNoInicio(n); //
    n = new Celula();
    n->valor = 5;
    numeros.inserirAoFinal(n); //
    n = new Celula();
    n->valor = 15;
    numeros.inserirNoInicio(n);//
    numeros.imprimir();

    return 0;
}

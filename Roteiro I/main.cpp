#include <iostream>
#include <fstream>
#include <string>
#include "Lista.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista numeros; //primeiro = NULL
    Lista numeros2; //primeiro = NULL
    numeros.inicializar();
    numeros2.inicializar();

    int vetor[] = {77,88,34,2,8,4,6,0,7,9};
    for (int i=0; i< 10; i++)
    {
        numeros.inserirAoFinal(vetor[i]);
        numeros2.inserirAoFinal((vetor[i]));
    }
    numeros.imprimir();
    numeros2.imprimir();
    numeros.unirLista(numeros2);
    numeros.imprimir();


   // numeros.inserirAoFinal(666);
    //numeros.imprimir();
   // numeros.nElementos();
    return 0;
}

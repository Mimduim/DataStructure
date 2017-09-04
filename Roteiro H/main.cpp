#include <iostream>
#include <fstream>
#include <string>
#include "Lista.cpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Lista numeros; //primeiro = NULL
    numeros.inicializar();

    int vetor[] = {77,88,34,2,8,4,6,0,7,9};
    for (int i=0; i< 10; i++)
    {
        numeros.inserirAoFinal(vetor[i]);
    }
    numeros.imprimir();

    return 0;
}

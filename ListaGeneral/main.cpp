#include <iostream>
#include "Lista.h"
//#include "ListaGeneral.cpp"
using namespace std;

int main()
{
     //Lista de inteiros
    Lista<int>* intLista = new Lista<int>();

    int vetor[] = {3,40,6,8,4,1,100,2};

    for(int i = 0; i < 8; i++)
    {
        intLista->InsereOrdem(vetor[i]);
    }
   intLista->mostra();



    return 0;
}

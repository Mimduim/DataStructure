#include <iostream>
#include <fstream>
#include <string>
#include "Lista.cpp"
#include "ListaString.cpp"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    /* 1.
        Lista numeros; //primeiro = NULL
        numeros.inicializar();

        int vetor[] = {77,88,34,2,8,4,6,0,7,9};
        for (int i=0; i< 10; i++)
        {
            numeros.inserirAoFinal(vetor[i]);
        }
        numeros.imprimir();
        numeros.removerFinal();
        numeros.removerInicio();
        numeros.imprimir();
    */

    /* 2.
    Lista numeros; //primeiro = NULL

    numeros.inicializar();

    int vetor[] = {77,88,34,2,8,4,6,0,7,9};
    for (int i=0; i< 10; i++)
    {
        numeros.insereOrdem(vetor[i]);
    }
    numeros.imprimir();
    */

    /* 3.
     Lista lista1;
     Lista lista2;
     lista1.inicializar();
     lista2.inicializar();

    int vetor1[] = {77,88,34,2,8,4,6,0,7,9};
    int vetor2[] = {0,1,2,3,4,5,6,7,8,9};

    for (int i=0; i< 10; i++)
    {
        lista1.insereOrdem(vetor1[i]);
        lista2.insereOrdem(vetor2[i]);
    }
    lista1.imprimir();
    lista2.imprimir();
    lista1.unirLista(lista2);
    lista1.imprimir();
    */

    /* 4.
     Lista lista1;
     Lista lista2;
     lista1.inicializar();
     lista2.inicializar();

    int vetor1[] = {77,88,34,2,8,4,6,0,7,9};
    int vetor2[] = {0,1,2,3,4,5,6,7,8,9};

    for (int i=0; i< 10; i++)
    {
        lista1.inserirAoFinal(vetor1[i]);
        lista2.inserirAoFinal(vetor2[i]);
    }

    lista1 = lista1.unirListaOrdem(lista2);
    lista1.imprimir();
    */

    /* 5.
    Lista lista1;
    Lista lista2;
    lista1.inicializar();
    lista2.inicializar();

    int vetor1[] = {77,88,34,2,8,4,6,0,7,9};
    int vetor2[] = {0,1,2,3,4,5,6,7,8,9};

    for (int i=0; i< 10; i++)
    {
        lista1.inserirAoFinal(vetor1[i]);
        lista2.inserirAoFinal(vetor2[i]);
    }
    lista1.imprimir();
    lista2.imprimir();
    //lista1 = lista1.intersecLista(lista2);
    lista2 = lista2.intersecLista(lista1);
    // lista1.imprimir();
    lista2.imprimir();

    */
    /* 6.
        Lista numeros; //primeiro = NULL
        numeros.inicializar();

        int vetor[] = {77,88,34,2,8,4,6,0,7,9};
        for (int i=0; i< 10; i++)
        {
            numeros.inserirAoFinal(vetor[i]);
        }
        numeros.imprimir();
        numeros.removeElemento(8);
        numeros.imprimir();

        delete[] vetor;
        */

    ListaString listaString;
    listaString.inicializar();
    ifstream ObjectReader ("arq.txt",ios_base::in);
    string conteiner;

    if (ObjectReader.is_open())
    {
        while (!ObjectReader.eof())
        {
            getline(ObjectReader, conteiner, ' ');
            listaString.inserirAoFinal(conteiner);
        }
        ObjectReader.close();
    }
    listaString.imprimir();

    return 0;
}

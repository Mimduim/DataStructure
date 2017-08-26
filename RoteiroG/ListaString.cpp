#include "ListaString.h"
void ListaString::inicializar()
{
    primeiro = NULL;
}

bool ListaString::vazia()
{
    return (primeiro == NULL);
}

void ListaString::inserirAoFinal(std::string palavra)
{
    CelulaString *nova = new CelulaString();
    nova->palavra = palavra;

    if(vazia())
    {
        primeiro = nova;
    }
    else
    {
        CelulaString* aux = primeiro;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = nova;
    }//fim do else
}
void ListaString::inserirNoInicio(std::string palavra)
{
    CelulaString *nova = new CelulaString();
    nova->palavra = palavra;

    nova->prox = primeiro;
    primeiro = nova;
}




void ListaString::imprimir()
{
    CelulaString* aux = primeiro;
    std::cout<<"Lista = [ ";
    while(aux != NULL)
    {
        std::cout<<aux->palavra<<" ";
        aux = aux->prox;
    }
    std::cout<<"]\n";
}



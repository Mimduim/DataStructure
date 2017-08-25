#include "Lista.h"
void Lista::inicializar()
{
    primeiro = NULL;
}

bool Lista::vazia()
{
    return (primeiro == NULL);
}

void Lista::inserirAoFinal(Celula* c)
{
    if(vazia())
    {
        primeiro = c;
    }
    else
    {
        Celula* aux = primeiro;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = c;
    }//fim do else
}
void Lista::inserirNoInicio(Celula* c)
{
    c->prox = primeiro;
    primeiro = c;
}

Celula* Lista::pesquisar(int v)
{
    if(vazia())
        return NULL;
    else
    {
        Celula* aux = primeiro;
        while(aux != NULL && aux->valor != v)
        {
            aux = aux->prox;
        }
        return aux;
    }
}

bool Lista::removerInicio()
{
    if(vazia())
    {
        return false;
    }
    else
    {
        Celula* aux = primeiro;
        if(aux->prox == NULL)
        {
            primeiro = NULL;
        }
        else
        {
            primeiro = aux->prox;
            aux->prox = NULL;
        }
        delete aux;
        return true;
    }
}

bool Lista::removerFinal()
{
    if(vazia())
    {
        return false;
    }
    else
    {
        Celula* ant = primeiro;
        Celula* atual = primeiro->prox;
        if(atual != NULL)
        {
            while(atual->prox != NULL)
            {
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = NULL;
        }
        else
        {
            atual = primeiro;
            primeiro = NULL;
        }
        delete atual;
        return true;
    }
}

void Lista::imprimir()
{
    Celula* aux = primeiro;
    while(aux != NULL)
    {
        std::cout<<"Valor = "<<aux->valor<<"\n";
        aux = aux->prox;
    }
}



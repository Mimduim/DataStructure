#include "Lista.h"
void Lista::inicializar()
{
    primeiro = new Celula();
    primeiro->valor = -1;
    primeiro->prox = primeiro;
}

bool Lista::vazia()
{
    return (primeiro->prox == primeiro);
}

void Lista::inserirAoFinal(int elemento)
{
    Celula *nova = new Celula();
    nova->valor = elemento;

    if(vazia())
    {
        primeiro->prox = nova;
        nova->prox = primeiro;
    }
    else
    {
        Celula* aux = primeiro->prox;
        while(aux->prox != primeiro)
        {
            aux = aux->prox;
        }
        aux->prox = nova;
        nova->prox = primeiro;
    }//fim do else
}
void Lista::inserirNoInicio(int elemento)
{
    Celula *nova = new Celula();
    Celula *aux = new Celula();

    aux = primeiro->prox;
    primeiro->prox = nova;
    nova->prox = aux;
}

int Lista::nElementos()
{
    int count = 0;
    Celula* aux = primeiro->prox;

    while(aux != primeiro)
    {
        count++;
        aux = aux->prox;
    }
    return count;

}

Celula* Lista::pesquisar(int elemento)
{
    if(vazia())
        return NULL;
    else
    {
        Celula* aux = primeiro->prox;
        while(aux != primeiro && aux->valor != elemento)
        {
            aux = aux->prox;
        }
        return aux;
    }
}

void Lista::insereOrdem(int elemento)
{
    Celula *atual = new Celula();
    Celula *anterior = new Celula();
    Celula *nova = new Celula();
    nova->valor = elemento;

    atual = primeiro;
    anterior = NULL;

    if(atual == NULL)
    {
        nova->prox = NULL;
        primeiro = nova;
    }
    else
    {
        while(atual != NULL && atual->valor < nova->valor)
        {
            anterior = atual;
            atual = atual->prox;
        }

        nova->prox = atual;

        if(anterior == NULL)
        {
            primeiro = nova;
        }
        else
        {
            anterior->prox = nova;
        }
    }

}

Lista Lista::unirLista(Lista lista)
{
    Lista listaProduto;
    listaProduto = lista;
    Celula* aux = primeiro;
    Celula* aux2 = listaProduto.primeiro;

    while(aux->prox != primeiro)
    {
        aux = aux->prox;
    }
    while(aux2->prox != listaProduto.primeiro)
    {
        aux2 = aux2->prox;
    }


    aux->prox = listaProduto.primeiro->prox;
    aux2->prox = primeiro;

    return listaProduto;
}

Lista Lista::unirListaOrdem(Lista lista)
{

    unirLista(lista);

    Lista listaProduto;
    listaProduto.inicializar();

    Celula* aux = primeiro;
    while(aux->prox != NULL)
    {
        listaProduto.insereOrdem(aux->valor);
        aux = aux->prox;
    }

    return listaProduto;
}

bool Lista::existeElemento(int elemento)
{

    Celula* aux = primeiro;

    while(aux->prox)
    {
        if (aux->valor == elemento)
            return true;
        else if(aux->prox->valor == elemento)
            return true;
        aux = aux->prox;
    }

    return false;

}

Lista Lista::intersecLista(Lista lista)
{
    Lista listInter;
    listInter.inicializar();

    Celula* aux = primeiro;
    Celula* aux2 = lista.primeiro;

    while(aux->prox != NULL)
    {
        if (existeElemento(aux2->valor) == 0)
        {
            listInter.inserirAoFinal(aux2->valor);
        }
        aux2 = aux2->prox;
        aux = aux->prox;
    }
    return listInter;
}

void Lista::removeElemento(int elemento)
{

    Celula *anterior = primeiro;
    Celula *atual = anterior->prox;

    if(vazia())
    {
        std::cout << "Lista vazia!\n";
    }
    else if( anterior->valor == elemento)
    {
        removerInicio();
    }
    else
    {
        while(atual != primeiro)
        {
            if(atual->valor == elemento)
            {
                anterior->prox = atual->prox;
                delete atual;
                break;
            }
            else
            {
                anterior = atual;
                atual = atual->prox;
            }
        }
    }
}

void Lista::clearList()
{
    primeiro->prox = NULL;
}

bool Lista::removerInicio()
{
    if(vazia())
    {
        return false;
    }
    else
    {
        Celula* aux = primeiro->prox;
        primeiro->prox = aux->prox;
        aux->prox = NULL;
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
        while(atual->prox != primeiro)
        {
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = primeiro;
        atual-> prox = NULL;
        delete atual;
        return true;
    }
}


void Lista::imprimir()
{
    Celula* aux = primeiro->prox;
    std::cout<<"Lista = [ ";
    while(aux != primeiro)
    {
        std::cout<<aux->valor<<" ";
        aux = aux->prox;
    }
    std::cout<<"]\n";
}

Lista Lista::intercalarListas(Lista lista)
{
    Lista listaProduto;
    listaProduto.inicializar();
    Celula *aux = primeiro->prox;
    Celula *aux2 = lista.primeiro->prox;






}


Lista Lista::ordenarLista(Lista lista)
{
    int size = lista.nElementos();
    int j,i;
    Celula* aux;
    Celula* auxI = lista.primeiro->prox;
    Celula* auxJ= aux->prox;

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (auxI->valor > auxJ->valor)
            {
                aux = auxI;
                auxI = auxJ;
                auxJ = aux;
            }
        }
    }

    return lista;
}


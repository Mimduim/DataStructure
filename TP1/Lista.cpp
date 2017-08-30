#include "Lista.h"

void Lista::inicializar(int lin, int colun)
{
    // Gera celula inicial da matriz/lista
    Celula* nova = new Celula();
    Linha = lin;
    Coluna = colun;
    primeiro = NULL;
    nova->linha = -1;
    nova->coluna = -1;
    primeiro = nova;
    primeiro->direita = primeiro;
    primeiro->baixo = primeiro;

    /*
    // Matriz está vazia, gera o primeiro elemento da linha da matriz/lista
    nova = new Celula();
    nova->valor = NULL;
    nova->linha = -1;
    nova->coluna = NULL;
    nova->direita = primeiro;
    primeiro->direita = nova;

    */
    // Laço de alocação da linha da matriz/lista
    int count = 0;
    while (count != lin)
    {
        Celula* aux = primeiro;
        while (aux->direita != primeiro)
        {
            aux = aux->direita;
        }

        nova = new Celula();
        nova->valor = NULL;
        nova->linha = -1;
        nova->coluna = NULL;

        nova->direita = primeiro;
        nova->baixo = nova;
        aux->direita = nova;

        count++;
    }

    // Laço de alocação da coluna da matriz/lista
    count = 0;
    while (count != colun)
    {
        Celula* aux = primeiro;
        while (aux->baixo != primeiro)
        {
            aux = aux->baixo;
        }

        nova = new Celula();
        nova->valor = NULL;
        nova->linha = NULL;
        nova->coluna = -1;

        nova->baixo = primeiro;
        nova->direita = nova;
        aux->baixo = nova;

        count++;
    }
}

void Lista::inserir(int lin, int colun, float val)
{
    // Celula nova a ser inserida na Matriz
    Celula* nova = new Celula();
    // Celula para armazenar a celula da posição inicial da estrutura inicial da Matriz
    Celula* auxlinha = new Celula();
    Celula* auxcoluna = new Celula();
    // Celula para armazenar a celula da posição x da estrutura inicial da Matriz
    Celula* auxlinha2 = new Celula();
    Celula* auxcoluna2 = new Celula();
    // Atribuindo os parametros as variaveis da nova celula
    nova->linha = lin;
    nova->coluna = colun;
    nova->valor = val;

    //Comandos para localizar e armazenar a posição linha e coluna do parametro da função na Matriz externa
    auxlinha = primeiro;
    int count = 0;
    while(count != nova->linha)
    {
        auxlinha = auxlinha->baixo;
        count++;
    }

    auxcoluna = primeiro;
    count = 0;
    while(count != nova->coluna)
    {
        auxcoluna = auxcoluna->direita;
        count++;
    }


    // Comandos para localizar a posição da linha da Matriz
    auxlinha2 = auxlinha;
    if (auxlinha->direita == auxlinha2)
    {
        auxlinha->direita = nova;
        nova->direita = auxlinha2;
    }
    else
    {
        while (auxlinha->direita != auxlinha2)
        {
            auxlinha = auxlinha->direita;
        }
        auxlinha->direita = nova;
        nova->direita = auxlinha2;
    }

    // Comandos para localizar a posição da coluna da Matriz
    auxcoluna2 = auxcoluna;
    if (auxcoluna->baixo == auxcoluna2)
    {
        auxcoluna->baixo = nova;
        nova->baixo = auxcoluna;
    }
    else
    {
        while (auxcoluna->baixo != auxcoluna2)
        {
            auxcoluna = auxcoluna->baixo;
        }
        auxcoluna->baixo = nova;
        nova->baixo = auxcoluna2;
    }
}

void Lista::imprimirBase()
{
    Celula* aux = primeiro;
    std::cout<<" ";
    while(aux->direita != primeiro)
    {
        std::cout<<""<<aux->linha;
        aux = aux->direita;
    }
    std::cout<< ""<<aux->linha;
    std::cout<<"\n";

    aux = primeiro->baixo;
    while(aux->baixo != primeiro)
    {
        std::cout<<" "<<aux->coluna<< " \n";
        aux = aux->baixo;
    }
    std::cout<<" "<<aux->coluna<< " \n";
    std::cout<<"\n";
}

void Lista::imprimirValor()
{
    Celula* aux = primeiro->baixo;
    aux = aux->baixo;
    Celula* temp = aux;
    std::cout<<" ";
    while(aux->direita != temp)
    {
        aux = aux->direita;
        std::cout<<" "<<aux->valor;
    }

    std::cout<<"\n";
}

void Lista::imprimirMatriz()
{
    Celula* aux = new Celula();
    Celula* temp = new Celula();


    aux = primeiro->baixo;
    temp = aux;

    for (int i=0; i<Linha; i++)
    {

        while(aux->direita != temp)
        {
            aux = aux->direita;
            std::cout<<"\t"<<aux->valor<<"\t";
        }
        std::cout<<"\n";

        aux = temp->baixo;
        temp = aux;
    }
}




/*
Aluno: Paulo Henrique Rodrigues da Cunha Santos
Nº: 0022012
Disciplina: Algoritmos e Estruturas de Dados 2
Trabalho Pratico 1
data: 03/09/2017
hora: 01:00
*/
#include "Lista.h"

// Função que inicializa
void Lista::inicializar(int lin, int colun)
{
    // Gera celula principal da matriz/lista
    Celula* nova = new Celula();
    Linha = lin;
    Coluna = colun;
    primeiro = NULL;
    nova->linha = -1;
    nova->coluna = -1;
    primeiro = nova;
    primeiro->direita = primeiro;
    primeiro->baixo = primeiro;

    // Laço de alocação da linha da matriz/lista
    int count = 0;
    while (count != lin)
    {
        Celula* aux = primeiro;
        while (aux->baixo != primeiro)
        {
            aux = aux->baixo;
        }

        nova = new Celula();
        nova->valor = NULL;
        nova->linha = -1;
        nova->coluna = NULL;

        Lista lista;
        lista.primeiro = nova;
        lista.primeiro->baixo = primeiro;
        lista.primeiro->direita = lista.primeiro;
        aux->baixo = lista.primeiro;
        count++;
    }

    // Laço de alocação da coluna da matriz/lista
    count = 0;
    while (count != colun)
    {
        Celula* aux = primeiro;
        while (aux->direita != primeiro)
        {
            aux = aux->direita;
        }

        nova = new Celula();
        nova->valor = NULL;
        nova->linha = NULL;
        nova->coluna = -1;
        // Aloca uma lista para cada elemento correspondente a linha e coluna
        //da estrutura de movimentação e orientação
        Lista lista;
        lista.primeiro = nova;
        lista.primeiro->direita = primeiro;
        lista.primeiro->baixo = lista.primeiro;
        aux->direita = lista.primeiro;
        count++;
    }
}

// Função que insere elementos na matriz
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

// Função para soma
Lista Lista::soma(Lista *listaA, Lista *listaB)
{
    Lista listaC;
    listaC.inicializar(listaA->Linha,listaB->Coluna);

        Celula* A = new Celula();
        Celula* B = new Celula();
        Celula* C = new Celula();
        Celula* tempA = new Celula();
        Celula* tempB = new Celula();

        // Localização e orientação na matriz
        A = listaA->primeiro->baixo;
        B = listaB->primeiro->baixo;
        tempA = A;
        tempB = B;


        for (int i=1; i<=Linha; i++)
        {
            while(A->direita != tempA)
            {
                A = A->direita;
                B = B->direita;
                C = new Celula();
                C->valor = A->valor + B->valor;
                C->linha = A->linha;
                C->coluna = A->coluna;
                listaC.inserir(C->linha, C->coluna, C->valor);
            }
            A = tempA->baixo;
            B = tempB->baixo;
            tempA = A;
            tempB = B;
        }
        return listaC;

}

Lista Lista::multi(Lista *listaA, Lista *listaB)
{
    Lista listaC;
    listaC.inicializar(listaA->Linha,listaB->Coluna);

        Celula* A = new Celula();
        Celula* B = new Celula();
        Celula* tempA = new Celula();
        Celula* tempB = new Celula();

        A = listaA->primeiro->baixo;
        B = listaB->primeiro->direita;
        tempA = A;
        tempB = B;

        float aux = 0;
     // Lações e iterações para movimentar a matriz para direita e para baixo
     // Caso não exista tal elemento correspondente para se multiplicar
     // a celula fica no aguardo enquanto a outra da lista adjacente interage
        for (int k=1; k<=listaA->Linha; k++)
        {
            for (int i=1; i<=listaB->Coluna; i++)
            {
                for (int j=1; j<=listaA->Linha; j++)
                {
                    if (A->direita->coluna < B->baixo->linha)
                    {
                        aux += 0;
                        A = A->direita;
                    }
                    else if (A->direita->coluna > B->baixo->linha)
                    {
                        aux += 0;
                        B = B->baixo;
                    }
                    else
                    {
                        A = A->direita;
                        B = B->baixo;
                        aux += A->valor * B->valor;
                    }
                }
                listaC.inserir(k, i, aux);
                aux = 0;
                A = tempA;
                B = tempB->direita;
                tempB = B;
            }
            B = listaB->primeiro->direita;
            tempB = B;
            A = tempA->baixo;
            tempA = A;
        }
        return listaC;

}

void Lista::economia()
{
    Celula* aux = new Celula();
    Celula* temp = new Celula();
    aux = primeiro->baixo;
    temp = aux;
    int count=0;
    double bytes=0;

    for (int i=0; i<Linha; i++)
    {
        while(aux->direita != temp)
        {
            aux = aux->direita;
            count++;
        }
        aux = temp->baixo;
        temp = aux;
    }

    bytes = (Linha * Coluna) * sizeof(Celula);
    std::cout<< "Matriz possui "<<bytes<< " de bytes sem alocacao dinamica.\n";
    count = count * sizeof(Celula);
    std::cout<< "Matriz possui "<<count<< " de bytes com alocacao dinamica.\n";
    count = bytes - count;
    std::cout<< "Matriz possui "<<count<< " de bytes com economia.\n";

}

void Lista::imprimirBase()
{
    Celula* aux = primeiro;
    std::cout<<" ";
    while(aux->direita != primeiro)
    {
        std::cout<<""<<aux->coluna;
        aux = aux->direita;
    }
    std::cout<< ""<<aux->coluna;
    std::cout<<"\n";

    aux = primeiro->baixo;
    while(aux->baixo != primeiro)
    {
        std::cout<<" "<<aux->linha<< " \n";
        aux = aux->baixo;
    }
    std::cout<<" "<<aux->linha<< " \n";
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
    int j;
    for (int i=1; i<=Linha; i++)
    {
        j = 1;
        while(aux->direita != temp)
        {
            aux = aux->direita;
            while (aux->coluna != j)
            {
                std::cout<<" "<<'|'<<i<<','<<j<<'|'<<','<<0<<"  \t";
                j++;
            }
            j = aux->coluna +1;
            std::cout<<" "<<'|'<<aux->linha<<','<<aux->coluna<<'|'<<','<<aux->valor<<" \t";
        }
        // Caso a celula não exista e precise imprimir mais zeros
        while (j < Coluna+1)
        {
            std::cout<<" "<<'|'<<i<<','<<j<<'|'<<','<<0<<"  \t";
            j++;
        }
        aux = temp->baixo;
        temp = aux;
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

void Lista::remover(int linha, int coluna)
{
    Celula *anterior = primeiro->baixo;
    Celula *atual = anterior->direita;
    Celula *inicio = anterior;

    for (int i=0; i<Linha; i++)
    {
        while(atual->direita != inicio)
        {
            if(atual->linha == linha && atual->coluna == coluna)
            {
                anterior->direita = atual->direita;
                delete atual;
                break;
            }
            else
            {
                anterior = atual;
                atual = atual->direita;
            }
        }
        if(atual->linha == linha && atual->coluna == coluna)
        {
            anterior->direita = atual->direita;
            delete atual;
        }
        anterior = inicio->baixo;
        atual = anterior->direita;
        inicio = anterior;
    }
}




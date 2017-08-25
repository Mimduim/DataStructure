#include <iostream>

using namespace std;

//Declara��o da classe utilizando o recurso de templates
template <class T>
class Lista
{
private:
    //Declara��o da struct 'n�'
    //T � um tipo gen�rico que ser� definido no momento de instanciar um objeto do tipo Lista
    //prox � um ponteiro para o pr�ximo elemento da lista
    struct no
    {
        T x;
        struct no *prox;
    };
    //O n� que sera instanciado no momento de inser��o na lista
    no *novo;
    //O n� inicial da lista
    no *lista;

public:
    //Construtor da classe
    Lista()
    {
        //Instanciamos o n� inicial da lista
        lista = new no;
        lista->prox = NULL;
    }

    //M�todo para inser��o no in�cio da lista
    void InsereInicio(T x)
    {
        novo = new no;
        novo->x = x;
        novo->prox = lista->prox;
        lista->prox = novo;
    }

    //M�todo para inser��o no final da lista
    void InsereFim(T x)
    {
        novo = new no;
        novo->x = x;
        novo->prox = NULL;
        //Utilizamos um n� auxiliar para n�o corrompermos a lista original ao percorr�-la
        no* aux = lista;

        while(aux->prox)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    //M�todo para inser��o dos elementos em ordem crescente
    void InsereOrdem(T x)
    {
        no *novo = new no;
        no *aux;

        novo->x = x;

        if(lista->prox != NULL)
        {
            if(x < lista->prox->x)
            {
                novo->prox = lista->prox;
                lista->prox = novo;
            }
            else
            {
                aux = lista;
                while(aux->prox)
                {
                    if(x < aux->prox->x)
                    {
                        novo->prox = aux->prox;
                        aux->prox = novo;
                        return;
                    }
                    aux = aux->prox;
                }
                novo->prox = NULL;
                aux->prox = novo;
            }
        }
        else
        {
            lista->prox = novo;
            novo->prox = NULL;
        }

    }

    //M�todo que verifica se determinado elemento existe na lista
    bool existe(T x)
    {
        no* aux = lista;

        while(aux->prox)
        {
            if(aux->prox->x == x)
                return true;
            aux = aux->prox;
        }

        return false;
    }

    //M�todo para retornar um elemento em determinada posi��o na lista (come�ando em 0)
    T get(int indice)
    {
        no* aux = lista;
        int i = 0;

        while(i <= indice && aux->prox)
        {
            aux = aux->prox;
            i++;
        }

        return aux->x;
    }

    //M�todo para limpar a lista
    void limpa()
    {
        lista->prox = NULL;
    }

    //M�todo para mostrar os elementos presentes na lista
    void mostra()
    {
        cout << endl;

        if(lista->prox == NULL)
        {
            cout << "Lista vazia";
            return;
        }

        no* aux = lista;

        while(aux->prox)
        {
            cout << aux->prox->x << " ";
            aux = aux->prox;
        }
    }
};

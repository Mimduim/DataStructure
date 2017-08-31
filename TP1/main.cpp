#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "Matriz.cpp"

using namespace std;

Matriz readFile(char *diretorio)
{
    Matriz matriz;
    ifstream ObjectReader(diretorio,ios_base::in);
    string conteiner;
    int linha=0,coluna=0,aux;
    float valor;

    if (ObjectReader.is_open())
    {
        getline(ObjectReader, conteiner, ',');
        linha = atoi(conteiner.c_str());
        getline(ObjectReader, conteiner, ',');
        coluna = atoi(conteiner.c_str());
        getline(ObjectReader, conteiner);
        aux = atoi(conteiner.c_str());

    }
    else cout << "Erro na abertura de arquivo!!" << endl;

    matriz.inicialize(linha,coluna);

    if (ObjectReader.is_open())
    {
        for (int i=0; i<aux; i++)
        {
            getline(ObjectReader, conteiner, ',');
            linha = atoi(conteiner.c_str());

            getline(ObjectReader, conteiner, ',');
            coluna = atoi(conteiner.c_str());

            getline(ObjectReader, conteiner);
            valor = atof(conteiner.c_str());

            matriz.leMatriz(linha,coluna,valor);
        }
        ObjectReader.close();
    }

    return matriz;
}

int main()
{
    char dir[20] = "MatrizA.txt";
    Matriz A;
    A = readFile(dir);

    char dir2[20] = "MatrizB.txt";
    Matriz B;
    B = readFile(dir2);


    cout<< "Matriz A \n\n";
    A.imprimeMatriz();
    cout<< "\nMatriz B \n\n";
    B.imprimeMatriz();

    Matriz C;
    C = C.somaMatriz(A,B);
    cout<< "\nMatriz C (A + B) \n\n";
    C.imprimeMatriz();

    Matriz D;
    D = D.multiplicaMatriz(A,B);
    cout<< "\nMatriz D (A * C) \n\n";
    D.imprimeMatriz();

    A.lista.economia();

    C.removeElemento(1,1,C);
    C.imprimeMatriz();
    return 0;
}

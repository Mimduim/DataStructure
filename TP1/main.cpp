/*
Aluno: Paulo Henrique Rodrigues da Cunha Santos
N�: 0022012
Disciplina: Algoritmos e Estruturas de Dados 2
Trabalho Pratico 1
data: 03/09/2017
hora: 01:00
*/
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
    int linha=0,coluna=0;
    float valor;

    if (ObjectReader.is_open())
    {
        getline(ObjectReader, conteiner, ',');
        linha = atoi(conteiner.c_str());
        getline(ObjectReader, conteiner);
        coluna = atoi(conteiner.c_str());
    }
    else cout << "Erro na abertura de arquivo!!" << endl;

    matriz.inicialize(linha,coluna);

    if (ObjectReader.is_open())
    {
        while (!ObjectReader.eof())
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

    cout<< "\nMatriz C (A + B) \n\n";
    Matriz C;
    C = C.somaMatriz(A,B);
    C.imprimeMatriz();

    cout<< "\nMatriz D (A * C) \n\n";
    Matriz D;
    D = D.multiplicaMatriz(A,B);
    D.imprimeMatriz();

    cout<< "\nMatriz D com n-esimo elemento removido \n\n";
    D.removeElemento(1,1);
    D.imprimeMatriz();

    cout<< "\nMatriz A economia \n\n";
    A.calculoEconomiaBytes();

    cout<< "\nMatriz B economia \n\n";
    B.calculoEconomiaBytes();

    return 0;
}

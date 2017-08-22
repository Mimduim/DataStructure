/*
Roteiro E
1) Implemente a leitura de um arquivo texto contendo na primeira linha
um número inteiro que representa a quantidade de pessoas a serem lidas.
Cada pessoa tem um código, uma base de cálculo e um nome. Crie uma
estrutura para armazenar as informações de cada pessoa. Guarde estas
pessoas lidas do arquivo em um vetor alocado dinamicamente após a
leitura da primeira linha do arquivo. Faça a impressão dos elementos do
vetor para verificar se os dados estão corretos. Utilize funções para cada
operação.
3
3, 4.5, Joaquim Fernandes
2, 3.7, Marcela Araujo
6, 2.0, Murilo Paulo
2) Usando as pessoas calculadas no Exercício 1, considere que cada pessoa
recebe um salário mínimo multiplicado por sua base de cálculo. Crie um
arquivo de saída em que cada linha possui o código, o nome e salário de
uma pessoa separado por vírgulas.
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include "Pessoa.h"

using namespace std;

int sizeFile()
{
    ifstream ObjectReader ("arq.txt",ios_base::in);
    string conteiner;
    int size;

    if (ObjectReader.is_open())
    {
        getline(ObjectReader, conteiner);
        size = atoi(conteiner.c_str());
    }

    else cout << "Erro na abertura de arquivo!!" << endl;
    ObjectReader.close();
    return size;
}

void printPessoa(Pessoa *pessoa)
{
    for (int i=0; i<sizeFile(); i++)
        cout <<"\nNome: " << (*(pessoa+i)).nome <<"\nCodigo: " << (*(pessoa+i)).codigo << "\nBase_Calc: " << (*(pessoa+i)).basecalc<<endl;
}

void wiriteFile(Pessoa *pessoa)
{
    ofstream ObjectWiriter("salario.txt",ios_base::out);
    if (ObjectWiriter.is_open())
    {
        for (int i=0; i<sizeFile(); i++)
            ObjectWiriter <<  (*(pessoa+i)).codigo << ',' << (*(pessoa+i)).nome << ',' <<(*(pessoa+i)).basecalc << ',' << (*(pessoa+i)).salario << "\n";
            cout << "\nGravacao feita com sucesso!!" << endl;
        ObjectWiriter.close();
    }
     else cout << "Erro na gravacao do arquivo!!" << endl;
}

void readFile(Pessoa *pessoa)
{
    ifstream ObjectReader ("arq.txt",ios_base::in);
    string conteiner;
    int size = sizeFile();

    if (ObjectReader.is_open())
    {
        for (int count = 0; count < size; count ++)
        {
            getline(ObjectReader, conteiner, ',');
            (*(pessoa+count)).codigo = atoi(conteiner.c_str());
            getline(ObjectReader, conteiner, ',');
            (*(pessoa+count)).basecalc = atof(conteiner.c_str());
            getline(ObjectReader, conteiner);
            (*(pessoa+count)).nome = conteiner;
        }
        ObjectReader.close();
    }
    else cout << "Erro na abertura de arquivo!!" << endl;
}

void baseSalario(Pessoa *pessoa)
{
    for (int count=0; count<sizeFile(); count++)
        (*(pessoa+count)).salario = (*(pessoa+count)).basecalc * 937.0;
}

int main()
{
    // pontgeiro do tipo Pessoa
    Pessoa *pessoa;
    // setqndo numero de linhas
    int size = sizeFile();
    // alocando espaço de memoria para 3 pessoas/linhas
    pessoa = new Pessoa[size];
    // lendo arquivo e setando vetor de struc Pessoa
    readFile(pessoa);
    // imprimindo vetor de struct Pessoa
    printPessoa(pessoa);
    // setando salario de acordo com a basecalc de cada elemento do vetor de struct
    baseSalario(pessoa);
    // gerando arquivo com dados de cada objeto dentro do struct
    wiriteFile(pessoa);
    delete[] pessoa;
    return 0;
}

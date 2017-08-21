/*
Roteiro E

1) Implemente a leitura de um arquivo texto contendo na primeira linha
um n�mero inteiro que representa a quantidade de pessoas a serem lidas.
Cada pessoa tem um c�digo, uma base de c�lculo e um nome. Crie uma
estrutura para armazenar as informa��es de cada pessoa. Guarde estas
pessoas lidas do arquivo em um vetor alocado dinamicamente ap�s a
leitura da primeira linha do arquivo. Fa�a a impress�o dos elementos do
vetor para verificar se os dados est�o corretos. Utilize fun��es para cada
opera��o.
3
3, 4.5, Joaquim Fernandes
2, 3.7, Marcela Araujo
6, 2.0, Murilo Paulo
2) Usando as pessoas calculadas no Exerc�cio 1, considere que cada pessoa
recebe um sal�rio m�nimo multiplicado por sua base de c�lculo. Crie um
arquivo de sa�da em que cada linha possui o c�digo, o nome e sal�rio de
uma pessoa separado por v�rgulas.
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Pessoa
{
    string nome;
    int codigo;
    float basecalc;
};

void printPessoa(Pessoa pessoa)
{
    cout <<"\nNome: " << pessoa.nome <<"\nCodigo: " << pessoa.codigo << "\nBase_Calc: " << pessoa.basecalc<<endl;
}

int main()
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

    //Pessoa pessoa[size];
    Pessoa *pessoa = new Pessoa[size];

    if (ObjectReader.is_open())
    {
       for (int count = 0; count < size; count ++){
            getline(ObjectReader, conteiner, ',');
            pessoa[count].codigo = atoi(conteiner.c_str());
            getline(ObjectReader, conteiner, ',');
            pessoa[count].basecalc = atof(conteiner.c_str());
            getline(ObjectReader, conteiner);
            pessoa[count].nome = conteiner;
        }
        ObjectReader.close();
    }

    else cout << "Erro na abertura de arquivo!!" << endl;

    for (int i=0; i<size; i++)
        printPessoa(pessoa[i]);


    /*

        for (int i=0; i<size; i++)
            pessoa[i].basecalc = pessoa[i].basecalc * 937.0;

        ofstream ObjectWriter("salario.txt",ios_base::out);

        if (ObjectWriter.is_open())
        {
            for (int i=0; i<size; i++)
                ObjectWriter <<  pessoa[i].codigo << ',' << pessoa[i].nome << ',' << pessoa[i].basecalc << "\n";

        }
    */

    delete[] pessoa;
    return 0;
}

#include <iostream>
#include <fstream>
#include "Matriz.cpp"

using namespace std;

int main()
{
    ifstream ObjectReader ("arq.txt",ios_base::in);
    string conteiner;

    int linha, coluna;
    float valor;

    if (ObjectReader.is_open())
    {
        getline(ObjectReader, conteiner, ',');
        linha = atoi(conteiner.c_str());
        getline(ObjectReader, conteiner);
        coluna = atoi(conteiner.c_str());
    }

    else cout << "Erro na abertura de arquivo!!" << endl;

    Matriz M = new Matriz();
    M.inicializar(lina,coluna);

    if (ObjectReader.is_open())
    {
        while (!ObjectReader.eof()){
            getline(ObjectReader, conteiner, ',');
            linha = atoi(conteiner.c_str());
            getline(ObjectReader, conteiner, ',');
            coluna = atoi(conteiner.c_str());
            getline(ObjectReader, conteiner);
            valor = atof(conteiner.c_str());
            M.AtribuiMatriz(linha,coluna,valor);
        }

        ObjectReader.close();
    }

    else cout << "Erro na abertura de arquivo!!" << endl;
    return 0;
}

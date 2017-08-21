#include "FileReader.h"


FileReader::FileReader(void){}
FileReader::~FileReader(void){}
void FileReader::readFile(char *diretorio, string *texto)
{
    ifstream read (diretorio, ios::in);

    if (read.is_open())
    {
        while (!read.eof())
        {
            getline(read, this->conteiner, ',');
            *texto += this->conteiner;
        }
        read.close();
    }

    else cout << "Erro na abertura do arquivo!!" << endl;

}

void FileReader::createVector(string texto, int vector[]){
for (int i = 0; i < texto.size()-1; i++)
        vector[i] = texto[i] - 48;
}

int FileReader::returnSize(string texto){
this->size = texto.length()-1;
return size;
}


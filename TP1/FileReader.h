#ifndef FILEREADER_H_INCLUDED
#define FILEREADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class FileReader{
private:
    char *diretorio;
    string conteiner;
    int size;
public:
    FileReader();
    ~FileReader();
    void readFile(char *diretorio, string *texto);
    void createVector(string texto, int vector[]);
    int returnSize(string texto);
};

#endif // FILEREADER_H_INCLUDED

#include "BaseLib.h"
#include "FileReader.cpp"
using namespace std;

int main()
{
    char dir[20] = "arq.txt";
    string text;
    FileReader fileReader;
    fileReader.readFile(dir, &text);
    int size = fileReader.returnSize(text);
    int vet[size];
    fileReader.createVector(text, vet);

    for (int i = 0; i < size; i++)
        cout << vet[i] << " ";

    delete[] dir;
    delete[] vet;
    return EXIT_SUCCESS;
}

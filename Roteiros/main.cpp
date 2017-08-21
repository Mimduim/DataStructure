#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*1. Construa uma função que receba um vetor de inteiros como parâmetro e
retorne a média dos valores.*/
float returnMedia(int vetor[])
{
    int count = 0;
    for (int i=0; i< sizeof(vetor); i++)
        count += vetor[i];
    float media = count / sizeof(vetor);
    return media;
}

/*2. Construa uma função que retorne o MDC - máximo divisor comum de dois
números inteiros recebidos como parâmetro*/
int returnMDC(int dividendo, int divisor)
{
    int mdc;
    if (dividendo % divisor == 0)
        return divisor;
    else
    {
        while ( mdc !=0 )
        {
            mdc = dividendo % divisor;
            dividendo = divisor;
            divisor = mdc;
        }
    }
    mdc = dividendo;
    return mdc;
}

/*3. Construa uma função que receba uma string como parâmetro e procure pela
ocorrência de um caracter x*/
bool searchCaracter(string texto, string caractere)
{
    if (texto.find(caractere) == -1)
        return false;
    return true;
}

/*4. Construa uma função que calcule o MDC - máximo divisor comum de dois
números inteiros de forma recursiva.*/
int returnMDCR(int dividendo, int divisor)
{
    if (dividendo % divisor == 0)
    {
        return divisor;
    }
    else
    {
        return returnMDCR(divisor,dividendo%divisor);
    }
}

/*5. Escreva uma função que retorne o menor elemento de um vetor de números
reais.*/
float returnMenor(float vetor[])
{
    float menor = vetor[0];
    for (int i=1; i< sizeof(vetor); i++)
    {
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }
    return menor;
}

/*6. Escreva uma função recursiva que retorne o menor elemento de um vetor de
números reais*/
int returnMenorR(int vetor[], int size)
{
      if (size == 1){
        return vetor[0];
    } else {
        int x = returnMenorR(vetor, size-1);
        if (x < vetor[size-1]){
            return x;
        }else{
            return vetor[size-1];
        }
    }
}
int main()
{
    //int vetor[5] = {1,2,3,4,0};
    //cout <<  returnMedia(vetor)<< endl;

    //cout << returnMDC(36,90);

    //cout << searchCaracter("Deus" , "e");

    //cout << returnMDCR(36,90);

    //cout << returnMenor(vetor);

    //cout << returnMenorR(vetor, 5);

    /*
    14. Não
    15. Sim
    16. mat é um vetor e não uma variavel de valor unico
    17. b)
    18. nada
    19. nada
    20. nada
    21. uma é um vetor de char e a outra é um ponteiro de char.
    22. a)
    23. *mat[i]i[j]
    24. o parametro de uma é um ponteiro de char, e a outra um vetor de char
    25. e)
    26. c)
    27. b)
    28. a) variavel sem tipo, b) função sem retorno, c) função sem retorno com parametro sem tipo, d) erro.
    */

    return EXIT_SUCCESS;
}

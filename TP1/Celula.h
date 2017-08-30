#ifndef CELULA_H_INCLUDED
#define CELULA_H_INCLUDED

struct Celula
{
    Celula *direita;
    Celula *baixo;
    int linha, coluna;
    float valor;
};

#endif // CELULA_H_INCLUDED

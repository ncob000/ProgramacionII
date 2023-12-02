#ifndef CADENAS_H
#define CADENAS_H

#include <iostream>
#include <string>
using namespace std;

int StringLength(string Cadena);
void StringCopy(string CadenaOrigen, string CadenaDestino);

int StringLength(string Cadena)
{
    int i = 0;
    while (Cadena[i] != '\0')
    {
        i++;
    }
    return i;
}

void StringCopy(string CadenaOrigen, string CadenaDestino)
{
    int i = 0;
    while (CadenaOrigen[i] != '\0')
    {
        CadenaDestino[i] = CadenaOrigen[i];
        i++;
    }

    CadenaDestino[i] = '\0';
}

#endif

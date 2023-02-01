#ifndef ALGORITMODELPINTOR_H
#define ALGORITMODELPINTOR_H

#include "imagen.h"

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class AlgoritmoDelPintor
{
public:
    AlgoritmoDelPintor(Imagen &img);

    Imagen aplicarAlgoritmo (int fInicial, int cInicial);

/* 7 0 1
 * 6 p 2
 * 5 4 3*/

private:
    Imagen imagen;

    vector<vector<bool>> matrizAnalisis;

    void inicializarMatriz(int fila, int columna);

    void pintarVecinos(int fila, int columna, Pixel pixelReferencia, unsigned int tolerancia);

    bool esVecino(Pixel pixReferencia, Pixel pixAnalisis, unsigned int tolerancia);

    unsigned int getRangoDeTolerancia(int maxRango);

    vector<int> vecinosF = {-1,-1,0,1,1,1,0,-1};

    vector<int> vecinosC = {0,1,1,1,0,-1,-1,-1};

};

#endif // ALGORITMODELPINTOR_H

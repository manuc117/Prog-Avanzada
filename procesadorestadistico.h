#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H

#include "imagen.h"

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class ProcesadorEstadistico
{
public:
    ProcesadorEstadistico();

    int getMinimoR(Imagen &img);

    int getMaximoR(Imagen &img);

    int getMinimoG(Imagen &img);

    int getMaximoG(Imagen &img);

    int getMinimoB(Imagen &img);

    int getMaximoB(Imagen &img);

    vector<int> getFrecuenciaR(Imagen &img);

    vector<int> getFrecuenciaG(Imagen &img);

    vector<int> getFrecuenciaB(Imagen &img);

    vector<int> getFrecuenciaPromedio(Imagen &img);

    int getRMasFrecuente(Imagen &img);

    int getGMasFrecuente(Imagen &img);

    int getBMasFrecuente(Imagen &img);

    vector<float> getPromedioRGB(Imagen &img);

    vector<float> getDesviacionEstandarRGB(Imagen &img);

    void informarDatosEstadisticos(Imagen &img);
};

#endif // PROCESADORESTADISTICO_H

#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H

#include "imagen.h"

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

    int getMaxFrecuenciaR(Imagen &img);

    int getMaxFrecuenciaG(Imagen &img);

    int getMaxFrecuenciaB(Imagen &img);
};

#endif // PROCESADORESTADISTICO_H

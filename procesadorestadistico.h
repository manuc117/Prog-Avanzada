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
};

#endif // PROCESADORESTADISTICO_H

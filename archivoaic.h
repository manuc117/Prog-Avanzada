#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H

#include "gestordearchivos.h"
#include <fstream>
#include <iostream>

using namespace std;

class ArchivoAIC: public GestorDeArchivos
{
public:
    ArchivoAIC();

    Imagen leer(string ruta) override;

    void guardar(Imagen *img) override;
};

#endif // ARCHIVOAIC_H

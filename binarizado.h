#ifndef BINARIZADO_H
#define BINARIZADO_H

#include "filtros.h"

#include <iostream>
#include <limits>

using  namespace std;

class Binarizado: public Filtros
{
public:
    Binarizado();

    Imagen aplicarFiltro(Imagen &img) override;

    bool sePuedeBinarizar(Imagen &img);

    int getNivelBinarizacion(Imagen &img);

private:

    int nivelBinarizacion;

};

#endif // BINARIZADO_H

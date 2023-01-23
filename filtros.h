#ifndef FILTROS_H
#define FILTROS_H

#include "imagen.h"

class Filtros
{
public:
    Filtros();

    virtual Imagen aplicarFiltro(Imagen &img) = 0;
};

#endif // FILTROS_H

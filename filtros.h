#ifndef FILTROS_H
#define FILTROS_H

#include "imagen.h"

class Filtros
{
public:
    Filtros();

    virtual void aplicarFiltro(Imagen &img);
};

#endif // FILTROS_H

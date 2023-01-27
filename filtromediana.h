#ifndef FILTROMEDIANA_H
#define FILTROMEDIANA_H

#include "filtros.h"
#include "imagen.h"

#include <vector>
#include <algorithm>

class FiltroMediana: public Filtros
{
public:
    FiltroMediana();

    Imagen aplicarFiltro (Imagen &img) override;
};

#endif // FILTROMEDIANA_H

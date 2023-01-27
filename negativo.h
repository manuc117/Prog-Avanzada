#ifndef NEGATIVO_H
#define NEGATIVO_H

#include "filtros.h"

class Negativo: public Filtros
{
public:
    Negativo();

    Imagen aplicarFiltro(Imagen &img) override;
};

#endif // NEGATIVO_H

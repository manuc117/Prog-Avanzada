#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H

#include "filtros.h"
#include "imagen.h"

class FiltroPasaBajos: public Filtros
{
public:
    FiltroPasaBajos();

    Imagen aplicarFiltro(Imagen &img) override;
};

#endif // FILTROPASABAJOS_H

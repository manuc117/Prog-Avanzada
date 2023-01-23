#ifndef FILTROPASAALTOS_H
#define FILTROPASAALTOS_H

#include "filtros.h"
#include "imagen.h"

class FiltroPasaAltos: public Filtros
{
public:
    FiltroPasaAltos();

    Imagen aplicarFiltro(Imagen &img) override;
};

#endif // FILTROPASAALTOS_H

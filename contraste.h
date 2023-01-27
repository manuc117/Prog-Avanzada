#ifndef CONTRASTE_H
#define CONTRASTE_H

#include "filtros.h"
#include "procesadorestadistico.h"

class Contraste: public Filtros
{
public:
    Contraste();

    Imagen aplicarFiltro(Imagen &img) override;
};

#endif // CONTRASTE_H

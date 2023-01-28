#ifndef BRILLO_H
#define BRILLO_H

#include "filtros.h"

#include <limits>
#include <iostream>

using namespace std;

class Brillo: public Filtros
{
public:
    Brillo(int opcion);

    Imagen aplicarFiltro (Imagen &img) override;

    void aumentarBrillo (Imagen &img);

    void reducirBrillo (Imagen &img);

    void getValor(Imagen &img);

private:
    int valor;

    char operacion;
};

#endif // BRILLO_H

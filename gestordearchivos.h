#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H

#include "imagen.h"
#include <string>

class GestorDeArchivos //clase abstracta, metodos virtuales puros, no se puede instanciar
{
public:

    virtual Imagen leer(string ruta) = 0;

    virtual void guardar(Imagen *img) = 0;

};

#endif // GESTORDEARCHIVOS_H

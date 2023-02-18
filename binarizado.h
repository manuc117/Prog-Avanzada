/*!
 *  \class      Binarizado
 *  \brief      Clase que hereda el método de la clase Filtros y lo redefine para binarizar una imagen.
 *  \details    Permite binarizar una imagen, siempre y cuando esta sea de intensidades. Es capaz
 *              de obtener el nivel a partir del cual se quiere binarizar la imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
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

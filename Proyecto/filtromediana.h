/*!
 *  \class      FiltroMediana
 *  \brief      Clase que hereda el método de la clase Filtros y lo redefine para aplicar el filtro
 *              de mediana sobre una imagen.
 *  \details    Permite aplicar el filtro de mediana sobre una imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROMEDIANA_H
#define FILTROMEDIANA_H

#include "filtros.h"
#include "imagen.h"

#include <vector>
#include <algorithm>

class FiltroMediana: public Filtros
{
public:
    /*!
     * \brief FiltroMediana Constructor del objeto FiltroMediana.
     */
    FiltroMediana();

    /*!
     * \brief aplicarFiltro Método heredado de la clase Filtros, redefinido
     *        para aplicar el filtro de mediana a una imagen.
     * \param img Imagen a la que se le aplica el filtro.
     * \return Imagen con el filtro aplicado.
     */
    Imagen aplicarFiltro (Imagen &img) override;
};

#endif // FILTROMEDIANA_H

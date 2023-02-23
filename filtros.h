/*!
 *  \class      Filtros
 *  \brief      Clase abstracta que hereda su método aplicar filtro a sus clases hijas.
 *  \details    Virtualiza su método de aplicación de un filtro para que las clases hijas
 *              puedan modificar una imagen de distintas maneras.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROS_H
#define FILTROS_H

#include "imagen.h"

class Filtros
{
public:

    /*!
     * \brief aplicarFiltro Método virtual para la aplicación de filtros.
     * \param[in] img Imagen sobre la cual se aplica un filtro.
     * \return Imagen con el filtro aplicado.
     */
    virtual Imagen aplicarFiltro(Imagen &img) = 0;
};

#endif // FILTROS_H

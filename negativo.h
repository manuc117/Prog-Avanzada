/*!
 *  \class      Negativo
 *  \brief      Clase que hereda el método de la clase Filtros y lo redefine para aplicar el filtro
 *              negativo sobre una imagen.
 *  \details    Permite aplicar el filtro negativo sobre una imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef NEGATIVO_H
#define NEGATIVO_H

#include "filtros.h"

class Negativo: public Filtros
{
public:
    /*!
     * \brief Negativo Constructor del objeto Negativo.
     */
    Negativo();

    /*!
     * \brief aplicarFiltro Método heredado de la clase Filtros, redefinido para
     *        aplicar el filtro negativo a una imagen.
     * \param img Imagen a la que se le aplica el filtro.
     * \return Imagen con el filtro aplicado.
     */
    Imagen aplicarFiltro(Imagen &img) override;
};

#endif // NEGATIVO_H

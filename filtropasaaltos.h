/*!
 *  \class      FiltroPasaBajos
 *  \brief      Clase que hereda el método de la clase Filtros y lo redefine para aplicar el filtro
 *              pasa altos sobre una imagen.
 *  \details    Permite aplicar el filtro de pasa altos sobre una imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROPASAALTOS_H
#define FILTROPASAALTOS_H

#include "filtros.h"
#include "imagen.h"

class FiltroPasaAltos: public Filtros
{
public:
    /*!
     * \brief FiltroPasaAltos Constructor del objeto FiltroPasaAltos.
     */
    FiltroPasaAltos();

    /*!
     * \brief aplicarFiltro Método heredado de la clase Filtros, redefinido
     *        para aplicar el filtro de pasa altos a una imagen.
     * \param img Imagen a la que se le aplica el filtro.
     * \return Imagen con el filtro aplicado.
     */
    Imagen aplicarFiltro(Imagen &img) override;
};

#endif // FILTROPASAALTOS_H

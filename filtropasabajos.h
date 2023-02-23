/*!
 *  \class      FiltroPasaBajos
 *  \brief      Clase que hereda el método de la clase Filtros y lo redefine para aplicar el filtro
 *              pasa bajos sobre una imagen.
 *  \details    Permite aplicar el filtro de pasa bajos o suavizado sobre una imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H

#include "filtros.h"
#include "imagen.h"

class FiltroPasaBajos: public Filtros
{
public:
    /*!
     * \brief FiltroPasaBajos Constructor del objeto FiltroPasaBajos.
     */
    FiltroPasaBajos();

    /*!
     * \brief aplicarFiltro Método heredado de la clase Filtros, redefinido
     *        para aplicar el filtro de suavizado a una imagen.
     * \param img Imagen a la que se le aplica el filtro.
     * \return Imagen con el filtro aplicado.
     */
    Imagen aplicarFiltro(Imagen &img) override;
};

#endif // FILTROPASABAJOS_H

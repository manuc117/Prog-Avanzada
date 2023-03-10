/*!
 *  \class      FiltroPasaBajos
 *  \brief      Clase que permite aplicar el filtro de pasa altos sobre una imagen.
 *              pasa altos sobre una imagen.
 *  \details    Hereda el método de la clase ProcesadorDeImagen y lo redefine para procesar una
 *              Imagen con el filtro de pasa altos.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROPASAALTOS_H
#define FILTROPASAALTOS_H

#include "procesadordeimagen.h"
#include "imagen.h"

class FiltroPasaAltos: public ProcesadorDeImagen
{
public:
    /*!
     * \brief FiltroPasaAltos Constructor del objeto FiltroPasaAltos.
     */
    FiltroPasaAltos();

    /*!
     * \brief procesarImagen Método heredado de la clase ProcesadorDeImagen, redefinido
     *        para aplicar el filtro de pasa altos a una imagen.
     * \param[in] img Imagen a la que se le aplica el filtro de pasa altos.
     * \return Imagen procesada.
     */
    Imagen procesarImagen(Imagen &img) override;
};

#endif // FILTROPASAALTOS_H

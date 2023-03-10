/*!
 *  \class      FiltroMediana
 *  \brief      Clase que permite aplicar el filtro de mediana sobre una imagen.
 *  \details    Hereda el método de la clase ProcesadorDeImagen y lo redefine para
 *              procesar una Imagen con el filtro de mediana.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROMEDIANA_H
#define FILTROMEDIANA_H

#include "procesadordeimagen.h"
#include "imagen.h"

#include <vector>
#include <algorithm>

class FiltroMediana: public ProcesadorDeImagen
{
public:
    /*!
     * \brief FiltroMediana Constructor del objeto FiltroMediana.
     */
    FiltroMediana();

    /*!
     * \brief procesarImagen Método heredado de la clase ProcesadorDeImagen, redefinido
     *        para aplicar el filtro de mediana a una imagen.
     * \param[in] img Imagen a la que se le aplica el filtro de mediana.
     * \return Imagen procesada.
     */
    Imagen procesarImagen (Imagen &img) override;
};

#endif // FILTROMEDIANA_H

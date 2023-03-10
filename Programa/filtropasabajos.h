/*!
 *  \class      FiltroPasaBajos
 *  \brief      Clase que permite aplicar el filtro de pasa bajos o suavizado sobre una Imagen.
 *  \details    Hereda el método de la clase ProcesadorDeImagen y lo redefine para procesar una Imagen
 *              con el filtro de pasa bajos o suavizado.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef FILTROPASABAJOS_H
#define FILTROPASABAJOS_H

#include "procesadordeimagen.h"
#include "imagen.h"

class FiltroPasaBajos: public ProcesadorDeImagen
{
public:
    /*!
     * \brief FiltroPasaBajos Constructor del objeto FiltroPasaBajos.
     */
    FiltroPasaBajos();

    /*!
     * \brief procesarImagen Método heredado de la clase ProcesadorDeImagen, redefinido
     *        para aplicar el filtro de suavizado a una imagen.
     * \param[in] img Imagen a la que se le aplica el filtro de suavizado.
     * \return Imagen procesada.
     */
    Imagen procesarImagen(Imagen &img) override;
};

#endif // FILTROPASABAJOS_H

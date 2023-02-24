/*!
 *  \class      Negativo
 *  \brief      Clase que permite obtener el negativo de una Imagen.
 *  \details    Hereda el método de la clase ProcesadorDeImagen y lo redefine para obtener el
 *              negativo de una Imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef NEGATIVO_H
#define NEGATIVO_H

#include "procesadordeimagen.h"

class Negativo: public ProcesadorDeImagen
{
public:
    /*!
     * \brief Negativo Constructor del objeto Negativo.
     */
    Negativo();

    /*!
     * \brief procesarImagen Método heredado de la clase ProcesadorDeImagen, redefinido para
     *        obtener el negativo de una imagen.
     * \param img Imagen que se procesa.
     * \return Imagen procesada.
     */
    Imagen procesarImagen(Imagen &img) override;
};

#endif // NEGATIVO_H

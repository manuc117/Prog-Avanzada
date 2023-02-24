/*!
 *  \class      Contraste
 *  \brief      Clase que permite ajustar el contraste de una Imagen.
 *  \details    Hereda el método de la clase ProcesadorDeImagen y lo redefine para
 *              ajustar el contraste sobre una imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef CONTRASTE_H
#define CONTRASTE_H

#include "procesadordeimagen.h"
#include "procesadorestadistico.h"

class Contraste: public ProcesadorDeImagen
{
public:
    /*!
     * \brief Contraste Constructor del objeto contraste.
     */
    Contraste();

    /*!
     * \brief procesarImagen Método heredado de la clase ProcesadorDeImagen, redefinido
     *        para ajustar el contraste a una imagen.
     * \param img Imagen a la que se le ajusta el contraste.
     * \return Imagen procesada.
     */
    Imagen procesarImagen(Imagen &img) override;
};

#endif // CONTRASTE_H

/*!
 *  \class      ProcesadorDeImagen
 *  \brief      Clase abstracta que hereda su método procesarImagen a sus clases hijas.
 *  \details    Virtualiza su método de procesamiento de Imagen para que las clases hijas
 *              puedan modificar una imagen de distintas maneras.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 24-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef PROCESADORDEIMAGEN_H
#define PROCESADORDEIMAGEN_H

#include "imagen.h"

class ProcesadorDeImagen
{
public:
    /*!
     * \brief ProcesadorDeImagen Constructor del objeto ProcesadorDeImagen.
     */
    ProcesadorDeImagen();

    /*!
     * \brief procesarImagen Método virtual para procesar una Imagen.
     * \param[in] img Imagen sobre la que se aplican procesamientos.
     * \return Imagen procesada.
     */
    virtual Imagen procesarImagen(Imagen &img) = 0;

    /*!
     * \brief ~ProcesadorDeImagen Destructor del objeto ProcesadorDeImagen.
     */
    virtual ~ProcesadorDeImagen();
};

#endif // PROCESADORDEIMAGEN_H

/*!
 *  \class      Binarizado
 *  \brief      Clase que permite binarizar una Imagen
 *  \details    Hereda el método de la clase ProcesadorDeImagen y lo redefine para binarizar una Imagen,
 *              siempre y cuando esta sea de intensidades. Es capaz de obtener el nivel a partir del
 *              cual se quiere binarizar la imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef BINARIZADO_H
#define BINARIZADO_H

#include "procesadordeimagen.h"

#include <iostream>
#include <limits>

using  namespace std;

class Binarizado: public ProcesadorDeImagen
{
public:
    /*!
     * \brief Binarizado Constructor del objeto Binarizado.
     */
    Binarizado();

    /*!
     * \brief procesarImagen Método heredado de la clase ProcesadorDeImagen, redefinido
     *        para binarizar una imagen de intensidades, a partir de un nivel seleccionado
     *        por el usuario.
     * \param[in] img Imagen que se procesa.
     * \return Imagen binarizada.
     */
    Imagen procesarImagen(Imagen &img) override;

private:

    /*!
     * \param nivelBinarizacion Número entero a partir del cuál se binariza
     *        la imagen.
     */
    int nivelBinarizacion;

    /*!
     * \brief sePuedeBinarizar Método que permite evaluar si una imagen se
     *        puede binarizar.
     * \param[in] img Imagen que se evalúa.
     * \return Devuelve verdadero (true) si se puede binarizar y falso (false) en
     *         caso contrario.
     */
    bool sePuedeBinarizar(Imagen &img);

    /*!
     * \brief getNivelBinarizacion Método que obtiene el nivel a partir del
     *        cual binarizar la imagen.
     * \param[in] img Imagen que se quiere binarizar.
     * \return Nivel a partir del cual se binariza la imagen.
     */
    int getNivelBinarizacion(Imagen &img);

};

#endif // BINARIZADO_H

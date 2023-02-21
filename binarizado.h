/*!
 *  \class      Binarizado
 *  \brief      Clase que hereda el método de la clase Filtros y lo redefine para binarizar una imagen.
 *  \details    Permite binarizar una imagen, siempre y cuando esta sea de intensidades. Es capaz
 *              de obtener el nivel a partir del cual se quiere binarizar la imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef BINARIZADO_H
#define BINARIZADO_H

#include "filtros.h"

#include <iostream>
#include <limits>

using  namespace std;

class Binarizado: public Filtros
{
public:
    /*!
     * \brief Binarizado Constructor del objeto Binarizado.
     */
    Binarizado();

    /*!
     * \brief aplicarFiltro Método heredado de la clase Filtros, redefinido
     *        para aplicar el binarizado a una imagen de intensidades, a partir
     *        de un nivel seleccionado por el usuario.
     * \param[in] img Imagen a la que se le aplica el binarizado.
     * \return Imagen binarizada.
     */
    Imagen aplicarFiltro(Imagen &img) override;

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

private:

    /*!
     * \param nivelBinarizacion Número entero a partir del cuál se binariza
     *        la imagen.
     */
    int nivelBinarizacion;

};

#endif // BINARIZADO_H

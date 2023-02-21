/*!
 *  \class      Brillo
 *  \brief      Clase que hereda el método de la clase Filtros y lo redefine para aumentar o
 *              reducir el brillo de una imagen.
 *  \details    Permite aumentar o reducir el brillo de una imagen a partir de un valor indicado
 *              por el usuario o uno por defecto (50).
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre        Se debe especificar si el objeto construido va aumentar o reducir el brillo.
 *  \bug
 *  \warning
*/
#ifndef BRILLO_H
#define BRILLO_H

#include "filtros.h"

#include <limits>
#include <iostream>

using namespace std;

class Brillo: public Filtros
{
public:
    /*!
     * \brief Brillo Constructor del objeto Brillo.
     * \param opcion Opcion que indica si se aumenta (1) o reduce el brillo (2).
     */
    Brillo(int opcion);

    /*!
     * \brief aplicarFiltro Método heredado de la clase Filtros, redefinido para
     *        modificar el brillo de una imagen.
     * \param[in] img Imagen a la que se le aplica el filtro.
     * \return Imagen con el filtro aplicado.
     */
    Imagen aplicarFiltro (Imagen &img) override;

    /*!
     * \brief aumentarBrillo Método que permite aumentar el brillo de una
     *        imagen.
     * \param[in] img Imagen a la que se le desea aplicar el filtro.
     * \param[out] img Imagen modificada con el brillo aumentado.
     */
    void aumentarBrillo (Imagen &img);

    /*!
     * \brief reducirBrillo Método que permite reducir el brillo de una imagen.
     * \param[in] img Imagen a la que se le desea aplicar el filtro.
     * \param[out] img Imagen modificada con el brillo reducido.
     */
    void reducirBrillo (Imagen &img);

    /*!
     * \brief getValor Método que permite obtener el nivel de brillo que se
     *        le quiere aumentar o reducir a una imagen.
     * \param img[in] Imagen a la que se le modifica el brillo.
     */
    void getValor(Imagen &img);

private:
    /*!
     * \param valor Número entero al cual se aumenta o reduce el brillo.
     */
    int valor;

    /*!
     * \param operacion Caracter que indica si se aplica el aumentarBrillo 'a' o el
     *        reducirBrillo 'r' a la imagen.
     */
    char operacion;
};

#endif // BRILLO_H

/*!
 *  \class      Brillo
 *  \brief      Clase que permite aumentar o reducir el brillo de una Imagen.
 *  \details    Hereda el método de la clase ProcesadorDeImagen y lo redefine para aumentar o
 *              reducir el brillo de una imagen, a partir de un valor indicado por el usuario
 *              o uno por defecto (50).
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre        Se debe especificar si el objeto construido va aumentar o reducir el brillo.
 *  \bug
 *  \warning
*/
#ifndef BRILLO_H
#define BRILLO_H

#include "procesadordeimagen.h"

#include <limits>
#include <iostream>

using namespace std;

class Brillo: public ProcesadorDeImagen
{
public:
    /*!
     * \brief Brillo Constructor del objeto Brillo.
     * \param[in] opcion Opcion que indica si se aumenta (1) o reduce el brillo (2).
     */
    Brillo(int opcion);

    /*!
     * \brief procesarImagen Método heredado de la clase ProcesadorDeImagen, redefinido para
     *        modificar el brillo de una imagen.
     * \param[in] img Imagen que se procesa.
     * \return Imagen procesada.
     */
    Imagen procesarImagen (Imagen &img) override;

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

    /*!
     * \brief aumentarBrillo Método que permite aumentar el brillo de una
     *        imagen.
     * \param[in] img Imagen a la que se le desea aumentar el brillo.
     * \param[out] img Imagen procesada con el brillo aumentado.
     */
    void aumentarBrillo (Imagen &img);

    /*!
     * \brief reducirBrillo Método que permite reducir el brillo de una imagen.
     * \param[in] img Imagen a la que se le desea reducir el brillo.
     * \param[out] img Imagen procesada con el brillo reducido.
     */
    void reducirBrillo (Imagen &img);

    /*!
     * \brief getValor Método que permite obtener el nivel de brillo que se
     *        le quiere aumentar o reducir a una imagen.
     * \param img[in] Imagen a la que se le modifica el brillo.
     */
    void getValor(Imagen &img);

};

#endif // BRILLO_H

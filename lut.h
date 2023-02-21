/*!
 *  \class      LUT
 *  \brief      Clase capaz de representar una Imagen pseudocoloreada con una tabla de conversión o LUT.
 *  \details    Tiene la capacidad de obtener un nivel de intensidad y, teniendo en cuenta este, devuelve
 *              un Pixel con el cual debe ser representado la misma.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre        Se debe especificar que con que LUT va a funcionar el objeto construido.
 *  \bug
 *  \warning
*/
#ifndef LUT_H
#define LUT_H

#include "imagen.h"

#include <string>
#include <vector>
#include <fstream>


class LUT
{
public:
    /*!
     * \brief LUT Constructor del objeto LUT
     * \param[in] opcion LUT que desea utilizarse.
     */
    LUT(int opcion);

    /*!
     * \brief pseudocolorear Método que permite devolver el Pixel con el cual
     *        debe ser representada la intensidad de un Pixel, a partir de esta.
     * \param[in] intensidad Nivel de intensidad del Pixel que se desea pseudocolorear.
     * \return Pixel pseudocoloreado.
     */
    Pixel pseudocolorear(int intensidad);

    /*!
     * \brief cargarTabla Método que permite cargar la tabla de conversión desde un
     *        archivo.
     * \param[in] opcion LUT que se desea utilizar.
     */
    void cargarTabla(int opcion);

private:

    /*!
     * \param grupoLuts Vector de strings que almacena las rutas de las LUTs
     *        que se pueden utilizar.
     */
    vector<string> grupoLuts
    {
        "./grupo_luts/glow.lut",
        "./grupo_luts/Turbo.lut"
    };

    /*!
     * \param tabla Arreglo bidimensional de enteros que representa la tabla de conversión[i][j].
     *        'i' representa la intensidad que se desea pseudocolorear y 'j' representa a R si
     *        es 1, a G si es 2 y a B si es 3. El entero almacenado es el valor de R, G o B por el
     *        que debe ser reemplazada la intensidad.
     */
    vector<vector<int>> tabla;
};

#endif // LUT_H

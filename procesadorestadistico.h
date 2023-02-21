/*!
 *  \class      ProcesadorEstadistico
 *  \brief      Clase capaz de realizar cálculos estadísticos varios.
 *  \details    Puede hacer diversos cálculos estadísticos como obtener la frecuencia
 *              de R, G o B, devolver el valor más frecuente de cada uno, hallar los
 *              valores máximo y mínimo, entre otros. Además permite informar los datos
 *              estadísticos de una imagen a partir de los cálculos realizados.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef PROCESADORESTADISTICO_H
#define PROCESADORESTADISTICO_H

#include "imagen.h"

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class ProcesadorEstadistico
{
public:
    /*!
     * \brief ProcesadorEstadistico Constructor del objeto ProcesadorEstadistico.
     */
    ProcesadorEstadistico();

    /*!
     * \brief getMinimoR Método que permite obtener el nivel mínimo de rojo que hay en
     *        una Imagen.
     * \param[in] img Imagen de la que se desea conocer el nivel mínimo de rojo.
     * \return Valor entero que representa el nivel mínimo de rojo.
     */
    int getMinimoR(Imagen &img);

    /*!
     * \brief getMaximoR Método que permite obtener el nivel máximo de rojo que hay en
     *        una Imagen.
     * \param[in] img Imagen de la que se desea conocer el nivel máximo de rojo.
     * \return Valor entero que representa el nivel máximo de rojo.
     */
    int getMaximoR(Imagen &img);

    /*!
     * \brief getMinimoG Método que permite obtener el nivel mínimo de verde que hay en
     *        una Imagen.
     * \param[in] img Imagen de la que se desea conocer el nivel mínimo de verde.
     * \return Valor entero que representa el nivel mínimo de verde.
     */
    int getMinimoG(Imagen &img);

    /*!
     * \brief getMaximoG Método que permite obtener el nivel máximo de verde que hay en
     *        una Imagen.
     * \param[in] img Imagen de la que se desea conocer el nivel máximo de verde.
     * \return Valor entero que representa el nivel máximo de verde.
     */
    int getMaximoG(Imagen &img);

    /*!
     * \brief getMinimoB Método que permite obtener el nivel mínimo de azul que hay en
     *        una Imagen.
     * \param[in] img Imagen de la que se desea conocer el nivel mínimo de azul.
     * \return Valor entero que representa el nivel mínimo de azul.
     */
    int getMinimoB(Imagen &img);

    /*!
     * \brief getMaximoB Método que permite obtener el nivel máximo de azul que hay en
     *        una Imagen.
     * \param[in] img Imagen de la que se desea conocer el nivel máximo de azul.
     * \return Valor entero que representa el nivel máximo de azul.
     */
    int getMaximoB(Imagen &img);

    /*!
     * \brief getFrecuenciaR Método que permite obtener la frecuencia de los distintos
     *        niveles de rojo.
     * \param[in] img Imagen de la que se desea conocer la frecuencia de rojo.
     * \return Vector de enteros donde cada posición equivale a un nivel de rojo y el entero
     *         contenido la frecuencia de dicho nivel.
     */
    vector<int> getFrecuenciaR(Imagen &img);

    /*!
     * \brief getFrecuenciaG Método que permite obtener la frecuencia de los distintos
     *        niveles de verde.
     * \param[in] img Imagen de la que se desea conocer la frecuencia de verde.
     * \return Vector de enteros donde cada posición equivale a un nivel de verde y el entero
     *         contenido la frecuencia de dicho nivel.
     */
    vector<int> getFrecuenciaG(Imagen &img);

    /*!
     * \brief getFrecuenciaB Método que permite obtener la frecuencia de los distintos
     *        niveles de azul.
     * \param[in] img Imagen de la que se desea conocer la frecuencia de azul.
     * \return Vector de enteros donde cada posición equivale a un nivel de azul y el entero
     *         contenido la frecuencia de dicho nivel.
     */
    vector<int> getFrecuenciaB(Imagen &img);

    /*!
     * \brief getFrecuenciaPromedio Método que permite obtener el promedio de la frecuencia de
     *        RGB para cada nivel de intensidad.
     * \param[in] img Imagen de la que se desea conocer la frecuencia promedio.
     * \return Vector de enteros donde cada posición equivale a un nivel de intensidad y el entero
     *         contenido la frecuencia de dicho nivel.
     */
    vector<int> getFrecuenciaPromedio(Imagen &img);

    /*!
     * \brief getRMasFrecuente Método que permite obtener el nivel de rojo más frecuente en una
     *        Imagen.
     * \param[in] img Imagen de la cual se desea conocer el nivel de rojo más frecuente.
     * \return Nivel de rojo que más se repite.
     */
    int getRMasFrecuente(Imagen &img);

    /*!
     * \brief getGMasFrecuente Método que permite obtener el nivel de verde más frecuente en una
     *        Imagen.
     * \param[in] img Imagen de la cual se desea conocer el nivel de verde más frecuente.
     * \return Nivel de verde que más se repite.
     */
    int getGMasFrecuente(Imagen &img);

    /*!
     * \brief getBMasFrecuente Método que permite obtener el nivel de azul más frecuente en una
     *        Imagen.
     * \param[in] img Imagen de la cual se desea conocer el nivel de azul más frecuente.
     * \return Nivel de azul que más se repite.
     */
    int getBMasFrecuente(Imagen &img);

    /*!
     * \brief getPromedioRGB Método que permite obtener el promedio de los niveles de R, G y B
     *        de una Imagen.
     * \param[in] img Imagen de la cual se desea conocer el promedio de R, G y B.
     * \return Vector de flotantes que contiene el promedio de R en la posición 0, el de G en la 1
     *         y el de B en la 2.
     */
    vector<float> getPromedioRGB(Imagen &img);

    /*!
     * \brief getDesviacionEstandarRGB Método que permite obtener las desviaciones estándar de R, G y B.
     * \param[in] img Imagen de la cual se desea conocer las desviaciones estándar.
     * \return Vector de flotantes que contiene la desviación estándar de R en la posición 0, la de G en
     *         la 1 y la de B en la 2.
     */
    vector<float> getDesviacionEstandarRGB(Imagen &img);

    /*!
     * \brief informarDatosEstadisticos Método que permite mostrar por pantalla los datos estadísticos
     *        de una Imagen.
     * \param[in] img Imagen de la cual se desea informar los datos estadísticos.
     */
    void informarDatosEstadisticos(Imagen &img);
};

#endif // PROCESADORESTADISTICO_H

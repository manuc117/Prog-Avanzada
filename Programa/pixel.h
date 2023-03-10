/*!
 *  \class      Pixel
 *  \brief      Clase que forma un pixel de una imagen.
 *  \details    Representa el pixel de cualquier tipo de imagen (RGB, de intensidades
 *              o monocromática). Posee valores enteros de rojo, verde y azul, los cuales
 *              puede devolver. Además puede calcular la intensidad del pixel a partir
 *              de estos tres valores.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:

    /*!
     * \brief Pixel Constructor vacío del objeto Pixel.
     */
    Pixel();

    /*!
     * \brief Pixel Constructor del objeto Pixel dandole valor a r, g y b.
     * \param r Valor de rojo.
     * \param g Valor de verde.
     * \param b Valor de azul.
     */
    Pixel(int r, int g, int b);

    /*!
     * \brief getRed Método que permite obtener el valor de rojo de un Pixel.
     * \return Valor entero de rojo.
     */
    int getRed();

    /*!
     * \brief getGreen Método que permite obtener el valor de verde de un Pixel.
     * \return Valor entero de verde.
     */
    int getGreen();

    /*!
     * \brief getBlue Método que permite obtener el valor de azul de un Pixel.
     * \return Valor entero de azul.
     */
    int getBlue();

    /*!
     * \brief setRed Método que permite establecer el valor de red.
     * \param[in] r Valor que se le va a asignar a r.
     */
    void setRed(int r);

    /*!
     * \brief setGreen Método que permite establecer el valor de green.
     * \param[in] r Valor que se le va a asignar a g.
     */
    void setGreen(int g);

    /*!
     * \brief setBlue Método que permite establecer el valor de blue.
     * \param[in] r Valor que se le va a asignar a red.
     */
    void setBlue(int b);

    /*!
     * \brief setPixelRGB Método que permite modificar los valores de R, G y B de
     *        un Pixel de tipo RGB o de intensidades.
     * \param[in] r Valor de rojo que se quiere establecer.
     * \param[in] g Valor de verde que se quiere establecer.
     * \param[in] b Valor de azul que se quiere establecer.
     */
    void setPixelRGB(int r, int g=-1, int b=-1);

    /*!
     * \brief setPixelMono Método que permite modificar los valores de R, G y B de
     *        un Pixel de tipo monocromático.
     * \param[in] valor Valor que se va a establecer en los tres parámetros.
     */
    void setPixelMono(int valor);

    /*!
     * \brief getIntensidad Método que permite obtener la intensidad de un Pixel.
     * \return Número entero que representa la intensidad de un Pixel ((R+G+B)/3).
     */
    int getIntensidad();

private:

    /*!
     * \param red Atributo que almacena el valor de rojo.
     * \param green Atributo que almacena el valor de verde.
     * \param blue Atributo que almacena el valor de azul.
     */
    int red, green, blue;

};

#endif // PIXEL_H

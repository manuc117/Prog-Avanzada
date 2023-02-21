/*!
 *  \class      Imagen
 *  \brief      Clase capaz de representar una imagen a partir de un arreglo de pixeles.
 *  \details    Conoce su cantidad de filas, columnas, sus pixeles, el rango de sus pixeles y
 *              su tamaño. Puede devolver dichos datos y modificar el tamaño y sus pixeles.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/

#ifndef IMAGEN_H
#define IMAGEN_H

#include "pixel.h"
#include <vector>
#include <string>

using namespace std;

class Imagen
{
public:
    /*!
     * \brief Imagen Constructor del objeto Imagen.
     */
    Imagen();

    /*!
     * \brief getFilas Método que permite obtener el número de filas de una Imagen.
     * \return Entero de 4 bytes que representa el número de filas de la Imagen.
     */
    int getFilas();

    /*!
     * \brief getColumnas Método que permite obtener el número de columnas de una Imagen
     * \return Entero de 4 bytes que representa el número de columnas de la Imagen.
     */
    int getColumnas();

    /*!
     * \brief getRango Método que permite obtener el rango de los pixeles de una Imagen.
     * \return Entero de 4 bytes que representa el rango.
     */
    int getRango();

    /*!
     * \brief setFilas Método que permite establecer el número filas de una Imagen.
     * \param[in] f Número de filas que se quiere establecer.
     */
    void setFilas(int f);

    /*!
     * \brief setColumnas Método que permite establecer el número de columnas de una Imagen.
     * \param[in] c Número de columnas que se quiere establecer.
     */
    void setColumnas(int c);

    /*!
     * \brief setRango Método que permite definir el rango leído de los pixeles de una Imagen.
     * \param[in] rang Valor de rango que se va a establecer.
     */
    void setRango(int rang);

    /*!
     * \brief getPixel Método que permite conocer un pixel de una Imagen en determinada
     *        posición.
     * \param[in] fila Fila del pixel que se quiere conocer.
     * \param[in] columna Columna del pixel que se quiere conocer.
     * \return Objeto del tipo Pixel.
     */
    Pixel getPixel(int fila, int columna); // Obtiene la posición del pixel

    /*!
     * \brief setPixel Método que permite modificar un Pixel de una Imagen.
     * \param pix Objeto Pixel que se va a modificar.
     * \param fila Fila en la que se encuentra el pixel a modificar.
     * \param columna Columna en la que se encuentra el pixel a modificar.
     */
    void setPixel(Pixel pix, int fila, int columna);

    /*!
     * \brief estaEnLaImagen Método booleano que permite saber si una coordenada (f,c)
     *        forma parte de una Imagen o no.
     * \param[in] fila Valor de la fila.
     * \param[in] columna Valor de la columna.
     * \return Booleano que indica que la coordenada está en la Imagen si su valor es true
     *         o que no está si su valor es false.
     */
    bool estaEnLaImagen(int fila, int columna); // Control

    /*!
     * \brief getIdentificador Método que permite conocer el código de identificación de una
     *        Imagen.
     * \return String que representa el código de identificación de la Imagen,
     */
    string getIdentificador();

    /*!
     * \brief setIdentificador Método que permite establecer el código de identificación de
     *        una Imagen.
     * \param[in] ci Código de identificación de la Imagen que se va a establecer.
     */
    void setIdentificador(string ci);

    /*!
     * \brief setTamanio Método que permite modificar el tamaño de una Imagen. Modifica el
     *        número de filas y de columnas.
     */
    void setTamanio();

    /*!
     * \brief setComentario Método que permite establecer el comentario de una Imagen.
     * \param[in] com Comentario de la Imagen que se va a establecer.
     */
    void setComentario(string com);

    /*!
     * \brief getComentario Método que permite obtener el comentario de una Imagen.
     * \return String que representa el comentario de la Imagen.
     */
    string getComentario();

private:
    /*!
     * \param imagen Arreglo bidimensional de pixeles que representa a una Imagen.
     *        Su tamaño está dado por las filas y las columnas de la Imagen.
     */
    vector<vector<Pixel>>imagen;

    /*!
     * \param filas Atributo que representa la cantidad de filas de una Imagen.
     */
    int filas;

    /*!
     * \param columnas Atributo que representa la cantidad de columnas de una Imagen.
     */
    int columnas;

    /*!
     * \param rango Atributo que representa el valor del rango de una Imagen.
     */
    int rango;

    /*!
     * \param identificador Atributo que representa el código de identificación
     *        de una Imagen.
     */
    string identificador; //código de identificación

    /*!
     * \param comentario Atributo que representa el comentario de una Imagen.
     */
    string comentario;
};

#endif // IMAGEN_H

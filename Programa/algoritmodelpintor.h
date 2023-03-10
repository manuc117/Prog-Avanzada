/*!
 *  \class      AlgoritmoDelPintor
 *  \brief      Clase capaz de aplicarle el algoritmo del pintor a una imagen.
 *  \details    Permite, a partir de un pixel inicial, buscar los vecinos de este teniendo
 *              en cuenta cierto nivel de tolerancia, especificado por el usuario. Si identifica
 *              un pixel como vecino, lo pinta con un color predeterminado (azul).
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 10-03-2023
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef ALGORITMODELPINTOR_H
#define ALGORITMODELPINTOR_H

#include "imagen.h"

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class AlgoritmoDelPintor
{
public:
    /*!
     * \brief AlgoritmoDelPintor Constructor del objeto AlgoritmoDelPintor.
     */
    AlgoritmoDelPintor();

    /*!
     * \brief aplicarAlgoritmo Método que permite aplicar el algoritmo del pintor.
     * \param[in] fInicial Valor de la fila del Pixel desde el cual se desean pintar
     *        los vecinos.
     * \param[in] cInicial Valor de la columna del Pixel desde el cual se desean pintar
     *        los vecinos.
     * \param[in] imagen Imagen sobre la que se aplica el algoritmo.
     * \return Imagen a la cual se le han modificado el Pixel inicial y sus vecinos.
     */
    Imagen aplicarAlgoritmo (int fInicial, int cInicial, Imagen &imagen);

private:
    /*!
     * \brief matrizAnalisis Matriz de booleanos del tamaño de la imagen. Cada elemento
     *        representa un Pixel de la imagen y el booleano almacenado tiene valor true
     *        si fue analizado y valor false en caso contrario.
     */
    vector<vector<bool>> matrizAnalisis;

    /*!
     * \brief inicializarMatriz Método que permite inicializar el atributo
     *        matrizAnalisis.
     * \param[in] filas Número de filas de la imagen.
     * \param[in] columnas Número de columnas de la imagen.
     */
    void inicializarMatriz(int filas, int columnas);

    /*!
     * \brief pintarVecinos Método privado que permite pintar los pixeles que sean vecinos.
     * \param fila Fila del Pixel bajo análisis.
     * \param columna Columna del Pixel bajo análisis.
     * \param pixelReferencia Pixel respecto al cual se analiza si otro Pixel es vecino.
     * \param tolerancia Rango de tolerancia según el cuál se determina si es vecino o no.
     * \param imagen Imagen a la que se le aplica el algoritmo.
     */
    void pintarVecinos(int fila, int columna, Pixel pixelReferencia, unsigned int tolerancia, Imagen &imagen);

    /*!
     * \brief esVecino Método que devuelve si un Pixel es vecino de otro o no.
     * \param[in] pixReferencia Pixel respecto al cual se analiza si otro Pixel es vecino.
     * \param[in] pixAnalisis Pixel bajo análisis.
     * \param[in] tolerancia Rango de tolerancia según el cuál se determina si es vecino o no.
     * \return Devuelve verdadero (true) si es vecino y falso (false) en
     *         caso contrario.
     */
    bool esVecino(Pixel pixReferencia, Pixel pixAnalisis, unsigned int tolerancia);

    /*!
     * \brief getRangoDeTolerancia Método privado que permite al usuario elegir el rango
     *        de tolerancia.
     * \param[in] maxRango Máximo rango de una imagen.
     * \return unsigned int que es el rango de tolerancia.
     */
    unsigned int getRangoDeTolerancia(int maxRango);

    /* 7 0 1
     * 6 p 2
     * 5 4 3*/

    /*!
     * \param vecinosF Vector de enteros que representan las filas de los vecinos.
     */
    vector<int> vecinosF = {-1,-1,0,1,1,1,0,-1};

    /*!
     * \param vecinosC Vector de enteros que representan las columnas de los vecinos.
     */
    vector<int> vecinosC = {0,1,1,1,0,-1,-1,-1};

    /*!
     * \param profundidad Profundidad de la llamada al método recursivo.
     */
    int profundidad;

    /*!
     * \param contadorPixeles Cantidad de pixeles que fueron pintados.
     */
    int contadorPixeles;

};

#endif // ALGORITMODELPINTOR_H

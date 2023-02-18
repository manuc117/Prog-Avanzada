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
    Imagen();

    int getFilas();

    int getColumnas();

    int getRango();

    void setFilas(int f);

    void setColumnas(int c);

    void setRango(int rang);

    Pixel getPixel(int fila, int columna); // Obtiene la posición del pixel

    void setPixel(Pixel pix, int fila, int columna);

    bool estaEnLaImagen(int fila, int columna); // Control

    string getIdentificador();

    void setIdentificador(string ci);

    void setTamanio();

    void setComentario(string com);

    string getComentario();

private:
    vector<vector<Pixel>>imagen;

    int filas;

    int columnas;

    int rango;

    string identificador; //código de identificación

    string comentario;
};

#endif // IMAGEN_H

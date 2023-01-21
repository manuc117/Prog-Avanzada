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

private:
    vector<vector<Pixel>>imagen;
    int filas;
    int columnas;
    int rango;
    string identificador; //código de identificación
    string comentario;
};

#endif // IMAGEN_H

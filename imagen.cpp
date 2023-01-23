#include "imagen.h"

Imagen::Imagen()
{

}

int Imagen::getFilas()
{
    return filas;
}

int Imagen::getColumnas()
{
    return columnas;
}

int Imagen::getRango()
{
    return rango;
}

void Imagen::setFilas(int f)
{
    filas = f;
}

void Imagen::setColumnas(int c)
{
    columnas = c;
}

void Imagen::setRango(int rang)
{
    rango = rang;
}

Pixel Imagen::getPixel(int fila, int columna)
{
    return imagen[fila][columna];
}

void Imagen::setPixel(Pixel pix, int fila, int columna)
{
    imagen[fila][columna] = pix;
}

bool Imagen::estaEnLaImagen(int fila, int columna)
{
    return fila<filas and columna<columnas and fila>=0 and columna>=0;
}

string Imagen::getIdentificador()
{
    return identificador;
}

void Imagen::setIdentificador(string ci)
{
    identificador = ci;
}

void Imagen::setTamanio()
{
    imagen.resize(filas);
    for (int i=0; i<filas; i++)
    {
        imagen[i].resize(columnas);
    }
}

void Imagen::setComentario(string com)
{
    comentario = com;
}

string Imagen::getComentario()
{
    return comentario;
}

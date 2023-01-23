#include "filtropasaaltos.h"

FiltroPasaAltos::FiltroPasaAltos()
{

}

Imagen FiltroPasaAltos::aplicarFiltro(Imagen &img)
{
    Imagen imagen = img;
    int auxRed, auxGreen, auxBlue;
    Pixel pixAux;

    int nColumnas = imagen.getColumnas(), nFilas = imagen.getFilas();

    for(int fila=0; fila<nFilas; fila++)
    {
        for(int columna=0; columna<nColumnas; columna ++)
        {
            pixAux = imagen.getPixel(fila,columna);

            auxRed = pixAux.getRed()*5;
            auxGreen = pixAux.getGreen()*5;
            auxBlue = pixAux.getBlue()*5;

            if(imagen.estaEnLaImagen(fila-1,columna))
            {
                pixAux = imagen.getPixel(fila-1, columna);
                auxRed += pixAux.getRed()*(-1);
                auxGreen += pixAux.getGreen()*(-1);
                auxBlue += pixAux.getBlue()*(-1);
            }

            if(imagen.estaEnLaImagen(fila,columna-1))
            {
                pixAux = imagen.getPixel(fila, columna-1);
                auxRed += pixAux.getRed()*(-1);
                auxGreen += pixAux.getGreen()*(-1);
                auxBlue += pixAux.getBlue()*(-1);
            }

            if(imagen.estaEnLaImagen(fila,columna+1))
            {
                pixAux = imagen.getPixel(fila, columna+1);
                auxRed += pixAux.getRed()*(-1);
                auxGreen += pixAux.getGreen()*(-1);
                auxBlue += pixAux.getBlue()*(-1);
            }

            if(imagen.estaEnLaImagen(fila+1,columna))
            {
                pixAux = imagen.getPixel(fila+1, columna);
                auxRed += pixAux.getRed()*(-1);
                auxGreen += pixAux.getGreen()*(-1);
                auxBlue += pixAux.getBlue()*(-1);
            }

            pixAux.setPixelRGB(auxRed, auxGreen, auxBlue);
            imagen.setPixel(pixAux, fila, columna);
        }
    }

    return imagen;
}



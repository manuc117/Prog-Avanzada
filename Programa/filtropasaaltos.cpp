#include "filtropasaaltos.h"

FiltroPasaAltos::FiltroPasaAltos()
{

}

Imagen FiltroPasaAltos::procesarImagen(Imagen &img)
{
    Imagen imagen = img;
    int auxRed, auxGreen, auxBlue;
    Pixel pixAux;

    int nColumnas = img.getColumnas(), nFilas = img.getFilas();

    for(int fila=0; fila<nFilas; fila++)
    {
        for(int columna=0; columna<nColumnas; columna ++)
        {
            pixAux = img.getPixel(fila,columna);

            auxRed = pixAux.getRed()*5;
            auxGreen = pixAux.getGreen()*5;
            auxBlue = pixAux.getBlue()*5;

            if(img.estaEnLaImagen(fila-1,columna))
            {
                pixAux = img.getPixel(fila-1, columna);
                auxRed += pixAux.getRed()*(-1);
                auxGreen += pixAux.getGreen()*(-1);
                auxBlue += pixAux.getBlue()*(-1);
            }

            if(img.estaEnLaImagen(fila,columna-1))
            {
                pixAux = img.getPixel(fila, columna-1);
                auxRed += pixAux.getRed()*(-1);
                auxGreen += pixAux.getGreen()*(-1);
                auxBlue += pixAux.getBlue()*(-1);
            }

            if(img.estaEnLaImagen(fila,columna+1))
            {
                pixAux = img.getPixel(fila, columna+1);
                auxRed += pixAux.getRed()*(-1);
                auxGreen += pixAux.getGreen()*(-1);
                auxBlue += pixAux.getBlue()*(-1);
            }

            if(img.estaEnLaImagen(fila+1,columna))
            {
                pixAux = img.getPixel(fila+1, columna);
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



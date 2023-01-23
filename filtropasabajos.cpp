#include "filtropasabajos.h"

FiltroPasaBajos::FiltroPasaBajos()
{

}

Imagen FiltroPasaBajos::aplicarFiltro(Imagen &img)
{
    Imagen imagen = img;
    float auxRed, auxGreen, auxBlue;
    Pixel pixAux;

    int nColumnas = imagen.getColumnas(), nFilas = imagen.getFilas();

    for(int fila=0; fila<nFilas; fila++)
    {
        for(int columna=0; columna<nColumnas; columna ++)
        {
            pixAux = imagen.getPixel(fila,columna);

            auxRed = pixAux.getRed();
            auxGreen = pixAux.getGreen();
            auxBlue = pixAux.getBlue();

            if(imagen.estaEnLaImagen(fila-1,columna-1))
            {
                pixAux = imagen.getPixel(fila-1, columna-1);
                auxRed += (float)pixAux.getRed()/9;
                auxGreen += (float)pixAux.getGreen()/9;
                auxBlue += (float)pixAux.getBlue()/9;
            }

            if(imagen.estaEnLaImagen(fila-1,columna))
            {
                pixAux = imagen.getPixel(fila-1, columna);
                auxRed += (float)pixAux.getRed()/9;
                auxGreen += (float)pixAux.getGreen()/9;
                auxBlue += (float)pixAux.getBlue()/9;
            }

            if(imagen.estaEnLaImagen(fila-1,columna+1))
            {
                pixAux = imagen.getPixel(fila-1, columna+1);
                auxRed += (float)pixAux.getRed()/9;
                auxGreen += (float)pixAux.getGreen()/9;
                auxBlue += (float)pixAux.getBlue()/9;
            }

            if(imagen.estaEnLaImagen(fila,columna-1))
            {
                pixAux = imagen.getPixel(fila, columna-1);
                auxRed += (float)pixAux.getRed()/9;
                auxGreen += (float)pixAux.getGreen()/9;
                auxBlue += (float)pixAux.getBlue()/9;
            }

            if(imagen.estaEnLaImagen(fila,columna+1))
            {
                pixAux = imagen.getPixel(fila, columna+1);
                auxRed += (float)pixAux.getRed()/9;
                auxGreen += (float)pixAux.getGreen()/9;
                auxBlue += (float)pixAux.getBlue()/9;
            }

            if(imagen.estaEnLaImagen(fila+1,columna-1))
            {
                pixAux = imagen.getPixel(fila+1, columna-1);
                auxRed += (float)pixAux.getRed()/9;
                auxGreen += (float)pixAux.getGreen()/9;
                auxBlue += (float)pixAux.getBlue()/9;
            }

            if(imagen.estaEnLaImagen(fila+1,columna))
            {
                pixAux = imagen.getPixel(fila+1, columna);
                auxRed += (float)pixAux.getRed()/9;
                auxGreen += (float)pixAux.getGreen()/9;
                auxBlue += (float)pixAux.getBlue()/9;
            }

            if(imagen.estaEnLaImagen(fila+1,columna+1))
            {
                pixAux = imagen.getPixel(fila-1, columna-1);
                auxRed += (float)pixAux.getRed()/9;
                auxGreen += (float)pixAux.getGreen()/9;
                auxBlue += (float)pixAux.getBlue()/9;
            }

            pixAux.setPixelRGB(auxRed, auxGreen, auxBlue);
            imagen.setPixel(pixAux, fila, columna);
        }
    }

    return imagen;
}

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
                auxRed += (float)pixAux.getRed();
                auxGreen += (float)pixAux.getGreen();
                auxBlue += (float)pixAux.getBlue();
            }

            if(imagen.estaEnLaImagen(fila-1,columna))
            {
                pixAux = imagen.getPixel(fila-1, columna);
                auxRed += (float)pixAux.getRed();
                auxGreen += (float)pixAux.getGreen();
                auxBlue += (float)pixAux.getBlue();
            }

            if(imagen.estaEnLaImagen(fila-1,columna+1))
            {
                pixAux = imagen.getPixel(fila-1, columna+1);
                auxRed += (float)pixAux.getRed();
                auxGreen += (float)pixAux.getGreen();
                auxBlue += (float)pixAux.getBlue();
            }

            if(imagen.estaEnLaImagen(fila,columna-1))
            {
                pixAux = imagen.getPixel(fila, columna-1);
                auxRed += (float)pixAux.getRed();
                auxGreen += (float)pixAux.getGreen();
                auxBlue += (float)pixAux.getBlue();
            }

            if(imagen.estaEnLaImagen(fila,columna+1))
            {
                pixAux = imagen.getPixel(fila, columna+1);
                auxRed += (float)pixAux.getRed();
                auxGreen += (float)pixAux.getGreen();
                auxBlue += (float)pixAux.getBlue();
            }

            if(imagen.estaEnLaImagen(fila+1,columna-1))
            {
                pixAux = imagen.getPixel(fila+1, columna-1);
                auxRed += (float)pixAux.getRed();
                auxGreen += (float)pixAux.getGreen();
                auxBlue += (float)pixAux.getBlue();
            }

            if(imagen.estaEnLaImagen(fila+1,columna))
            {
                pixAux = imagen.getPixel(fila+1, columna);
                auxRed += (float)pixAux.getRed();
                auxGreen += (float)pixAux.getGreen();
                auxBlue += (float)pixAux.getBlue();
            }

            if(imagen.estaEnLaImagen(fila+1,columna+1))
            {
                pixAux = imagen.getPixel(fila+1, columna+1);
                auxRed += (float)pixAux.getRed();
                auxGreen += (float)pixAux.getGreen();
                auxBlue += (float)pixAux.getBlue();
            }

            pixAux.setPixelRGB(auxRed/9, auxGreen/9, auxBlue/9);
            imagen.setPixel(pixAux, fila, columna);
        }
    }

    return imagen;
}

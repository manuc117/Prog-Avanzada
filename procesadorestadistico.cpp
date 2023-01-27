#include "procesadorestadistico.h"

ProcesadorEstadistico::ProcesadorEstadistico()
{

}

int ProcesadorEstadistico::getMinimoR(Imagen &img)
{
    Pixel pixelAux;
    int minimo = img.getPixel(0,0).getRed();

    int nfilas = img.getFilas(), ncolumnas = img.getColumnas();

    for(int f=0; f<nfilas; f++)
    {
        for(int c=0; c<ncolumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            if(pixelAux.getRed() < minimo)
            {
                minimo = pixelAux.getRed();
            }
        }
    }
    return minimo;
}

int ProcesadorEstadistico::getMaximoR(Imagen &img)
{
    int maximo = 0;
    Pixel pixelAux;

    int nfilas = img.getFilas(), ncolumnas = img.getColumnas();

    for(int f=0; f<nfilas; f++)
    {
        for(int c=0; c<ncolumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            if(pixelAux.getRed() > maximo)
            {
                maximo = pixelAux.getRed();
            }
        }
    }
    return maximo;
}

int ProcesadorEstadistico::getMinimoG(Imagen &img)
{
    Pixel pixelAux;
    int minimo = img.getPixel(0,0).getGreen();

    int nfilas = img.getFilas(), ncolumnas = img.getColumnas();

    for(int f=0; f<nfilas; f++)
    {
        for(int c=0; c<ncolumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            if(pixelAux.getGreen() < minimo)
            {
                minimo = pixelAux.getGreen();
            }
        }
    }
    return minimo;
}

int ProcesadorEstadistico::getMaximoG(Imagen &img)
{
    int maximo = 0;
    Pixel pixelAux;

    int nfilas = img.getFilas(), ncolumnas = img.getColumnas();

    for(int f=0; f<nfilas; f++)
    {
        for(int c=0; c<ncolumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            if(pixelAux.getGreen() > maximo)
            {
                maximo = pixelAux.getGreen();
            }
        }
    }
    return maximo;
}

int ProcesadorEstadistico::getMinimoB(Imagen &img)
{
    Pixel pixelAux;
    int minimo = img.getPixel(0,0).getBlue();

    int nfilas = img.getFilas(), ncolumnas = img.getColumnas();

    for(int f=0; f<nfilas; f++)
    {
        for(int c=0; c<ncolumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            if(pixelAux.getBlue() < minimo)
            {
                minimo = pixelAux.getBlue();
            }
        }
    }
    return minimo;
}

int ProcesadorEstadistico::getMaximoB(Imagen &img)
{
    int maximo = 0;
    Pixel pixelAux;

    int nfilas = img.getFilas(), ncolumnas = img.getColumnas();

    for(int f=0; f<nfilas; f++)
    {
        for(int c=0; c<ncolumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            if(pixelAux.getBlue() > maximo)
            {
                maximo = pixelAux.getBlue();
            }
        }
    }
    return maximo;
}

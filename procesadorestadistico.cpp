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

vector<int> ProcesadorEstadistico::getFrecuenciaR(Imagen &img)
{
    vector<int> frecuenciaRed;
    unsigned int auxRed;

    frecuenciaRed.resize(img.getRango()+1, 0);

    int nfilas = img.getFilas(), ncolumnas = img.getColumnas();

    for (int f=0; f<nfilas; f++)
    {
        for (int c=0; c<ncolumnas; c++)
        {
            auxRed = img.getPixel(f,c).getRed();

            frecuenciaRed[auxRed]++;
        }
    }

    return frecuenciaRed;
}

vector<int> ProcesadorEstadistico::getFrecuenciaG(Imagen &img)
{
    vector<int> frecuenciaGreen;
    unsigned int auxGreen;

    frecuenciaGreen.resize(img.getRango()+1, 0);

    int nfilas = img.getFilas(), ncolumnas = img.getColumnas();

    for (int f=0; f<nfilas; f++)
    {
        for (int c=0; c<ncolumnas; c++)
        {
            auxGreen = img.getPixel(f,c).getGreen();

            frecuenciaGreen[auxGreen]++;
        }
    }

    return frecuenciaGreen;
}

vector<int> ProcesadorEstadistico::getFrecuenciaB(Imagen &img)
{
    vector<int> frecuenciaBlue;
    unsigned int auxBlue;

    frecuenciaBlue.resize(img.getRango()+1, 0);

    int nfilas = img.getFilas(), ncolumnas = img.getColumnas();

    for (int f=0; f<nfilas; f++)
    {
        for (int c=0; c<ncolumnas; c++)
        {
            auxBlue = img.getPixel(f,c).getBlue();

            frecuenciaBlue[auxBlue]++;
        }
    }

    return frecuenciaBlue;
}

int ProcesadorEstadistico::getMaxFrecuenciaR(Imagen &img)
{
    vector<int> frecuencias = getFrecuenciaR(img);

    int mayor = 0, rMasFrec = 0;

    for(int i=0; i<frecuencias.size(); i++)
    {
        if(frecuencias[i] > mayor)
        {
            rMasFrec = i;
            mayor = frecuencias[i];
        }
    }

    return rMasFrec;
}

int ProcesadorEstadistico::getMaxFrecuenciaG(Imagen &img)
{
    vector<int> frecuencias = getFrecuenciaG(img);

    int mayor = 0, gMasFrec = 0;

    for(int i=0; i<frecuencias.size(); i++)
    {
        if(frecuencias[i] > mayor)
        {
            gMasFrec = i;
            mayor = frecuencias[i];
        }
    }

    return gMasFrec;
}

int ProcesadorEstadistico::getMaxFrecuenciaB(Imagen &img)
{
    vector<int> frecuencias = getFrecuenciaB(img);

    int mayor = 0, bMasFrec = 0;

    for(int i=0; i<frecuencias.size(); i++)
    {
        if(frecuencias[i] > mayor)
        {
            bMasFrec = i;
            mayor = frecuencias[i];
        }
    }

    return bMasFrec;
}



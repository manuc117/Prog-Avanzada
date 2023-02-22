#include "procesadorestadistico.h"

ProcesadorEstadistico::ProcesadorEstadistico()
{

}

int ProcesadorEstadistico::getMinimoR(Imagen &img)
{
    Pixel pixelAux;
    int minimo = img.getPixel(0,0).getRed();

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for(int f=0; f<nFilas; f++)
    {
        for(int c=0; c<nColumnas; c++)
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

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for(int f=0; f<nFilas; f++)
    {
        for(int c=0; c<nColumnas; c++)
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

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for(int f=0; f<nFilas; f++)
    {
        for(int c=0; c<nColumnas; c++)
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

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for(int f=0; f<nFilas; f++)
    {
        for(int c=0; c<nColumnas; c++)
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

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for(int f=0; f<nFilas; f++)
    {
        for(int c=0; c<nColumnas; c++)
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

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for(int f=0; f<nFilas; f++)
    {
        for(int c=0; c<nColumnas; c++)
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

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for (int f=0; f<nFilas; f++)
    {
        for (int c=0; c<nColumnas; c++)
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

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for (int f=0; f<nFilas; f++)
    {
        for (int c=0; c<nColumnas; c++)
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

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for (int f=0; f<nFilas; f++)
    {
        for (int c=0; c<nColumnas; c++)
        {
            auxBlue = img.getPixel(f,c).getBlue();

            frecuenciaBlue[auxBlue]++;
        }
    }

    return frecuenciaBlue;
}

vector<int> ProcesadorEstadistico::getFrecuenciaIntensidad(Imagen &img)
{
    return getFrecuenciaR(img);
}

vector<int> ProcesadorEstadistico::getFrecuenciaPromedio(Imagen &img)
{
    vector<int> frecuenciasR = getFrecuenciaR(img);
    vector<int> frecuenciasG = getFrecuenciaG(img);
    vector<int> frecuenciasB = getFrecuenciaB(img);

    vector<int> promedios;

    for(int nivel=0; nivel<frecuenciasR.size(); nivel++)
    {
        promedios.push_back(float(frecuenciasR[nivel]+frecuenciasG[nivel]+frecuenciasB[nivel])/3);
    }

    return promedios;
}

int ProcesadorEstadistico::getRMasFrecuente(Imagen &img)
{
    vector<int> frecuencias = getFrecuenciaR(img);

    int mayor = 0, red = 0;

    for(int i = 0; i < frecuencias.size(); i++)
        if (frecuencias[i] > mayor)
        {
            red = i;
            mayor = frecuencias[i];
        }

    return red;
}

int ProcesadorEstadistico::getGMasFrecuente(Imagen &img)
{
    vector<int> frecuencias = getFrecuenciaG(img);

    int mayor = 0, green = 0;

    for(int i = 0; i < frecuencias.size(); i++)
        if (frecuencias[i] > mayor)
        {
            green = i;
            mayor = frecuencias[i];
        }

    return green;
}

int ProcesadorEstadistico::getBMasFrecuente(Imagen &img)
{
    vector<int> frecuencias = getFrecuenciaB(img);

    int mayor = 0, blue = 0;

    for(int i = 0; i < frecuencias.size(); i++)
        if (frecuencias[i] > mayor)
        {
            blue = i;
            mayor = frecuencias[i];
        }

    return blue;
}

int ProcesadorEstadistico::getIntensidadMasFrecuente(Imagen &img)
{
    vector<int> frecuencias = getFrecuenciaIntensidad(img);

    int mayor = 0, intensidad = 0;

    for(int i = 0; i < frecuencias.size(); i++)
        if (frecuencias[i] > mayor)
        {
            intensidad = i;
            mayor = frecuencias[i];
        }

    return intensidad;
}

int ProcesadorEstadistico::getIntensidadMedia(Imagen &img)
{
    int sumaIntensidades = 0, contadorPixeles = 0;

    for(int f=0; f<img.getFilas(); f++)
    {
        for(int c=0; c<img.getColumnas(); c++)
        {
            sumaIntensidades += img.getPixel(f,c).getIntensidad();
            contadorPixeles++;
        }
    }

    return sumaIntensidades/contadorPixeles;
}

vector<float> ProcesadorEstadistico::getPromedioRGB(Imagen &img)
{
    vector<float> promedios(3);

    int nPixeles = img.getFilas()*img.getColumnas();

    vector<int> frecuenciasR = getFrecuenciaR(img);
    vector<int> frecuenciasG = getFrecuenciaG(img);
    vector<int> frecuenciasB = getFrecuenciaB(img);

    int sumaR = 0, sumaG = 0, sumaB = 0;

    for(int i=0; i<frecuenciasR.size(); i++) //i=nivel
    {
        sumaR += frecuenciasR[i]*i;
        sumaG += frecuenciasG[i]*i;
        sumaB += frecuenciasB[i]*i;
    }

    promedios[0] = float(sumaR/nPixeles);
    promedios[1] = float(sumaG/nPixeles);
    promedios[2] = float(sumaB/nPixeles);

    return promedios;
}

vector<float> ProcesadorEstadistico::getDesviacionEstandarRGB(Imagen &img)
{
    vector<float> desviaciones(3);

    vector<float> medias = getPromedioRGB(img);

    vector<int> frecuenciasR = getFrecuenciaR(img);
    vector<int> frecuenciasG = getFrecuenciaG(img);
    vector<int> frecuenciasB = getFrecuenciaB(img);

    int nPixeles = img.getFilas()*img.getColumnas();

    int sumaR = 0, sumaG = 0, sumaB = 0;


    for(int i=0; i<frecuenciasR.size(); i++)
    {
        sumaR += pow((i-medias[0]), 2)*frecuenciasR[i];
        sumaG += pow((i-medias[1]), 2)*frecuenciasG[i];
        sumaB += pow((i-medias[2]), 2)*frecuenciasB[i];
    }

    desviaciones[0] = sqrt(sumaR/nPixeles);
    desviaciones[1] = sqrt(sumaG/nPixeles);
    desviaciones[2] = sqrt(sumaB/nPixeles);

    return desviaciones;
}

void ProcesadorEstadistico::informarDatosEstadisticos(Imagen &img)
{
    cout<<"\t----Datos estadisticos----\n";
    cout<<"\tMinimo:\n\t\t-R:"<<getMinimoR(img)<<"\n\t\t-G:"<<getMinimoG(img)<<"\n\t\t-B:"<<getMinimoB(img);
    cout<<"\n\tMaximo:\n\t\t-R:"<<getMaximoR(img)<<"\n\t\t-G:"<<getMaximoG(img)<<"\n\t\t-B:"<<getMaximoB(img);
    cout<<"\n\tPromedio:\n\t\t-R:"<<getPromedioRGB(img).at(0)<<"\n\t\t-G:"<<getPromedioRGB(img).at(1)<<"\n\t\t-B:"<<getPromedioRGB(img).at(2);
    cout<<"\n\tDesviacion estandar:\n\t\t-R:"<<getDesviacionEstandarRGB(img).at(0)<<"\n\t\t-G:"<<getDesviacionEstandarRGB(img).at(1)<<"\n\t\t-B:"<<getDesviacionEstandarRGB(img).at(2);
    cout<<"\n\tModa o Maxima frecuencia:\n\t\t-R:"<<getRMasFrecuente(img)<<"\n\t\t-G:"<<getGMasFrecuente(img)<<"\n\t\t-B:"<<getBMasFrecuente(img)<<"\n";
}









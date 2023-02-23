#include "filtromediana.h"

FiltroMediana::FiltroMediana()
{

}

Imagen FiltroMediana::aplicarFiltro(Imagen &img)
{
    Imagen imagen = img;
    unsigned int auxRed, auxGreen, auxBlue;
    Pixel pixAux;

    int nColumnas = img.getColumnas(), nFilas = img.getFilas();
    int medio;

    vector<int> vecRed, vecGreen, vecBlue;

    for(int fila=0; fila<nFilas; fila++)
    {
        for(int columna=0; columna<nColumnas; columna ++)
        {
            pixAux = img.getPixel(fila,columna);

            vecRed.push_back(pixAux.getRed());
            vecGreen.push_back(pixAux.getGreen());
            vecBlue.push_back(pixAux.getBlue());

            if(img.estaEnLaImagen(fila-1,columna-1))
            {
                pixAux = img.getPixel(fila-1, columna-1);
                vecRed.push_back(pixAux.getRed());
                vecGreen.push_back(pixAux.getGreen());
                vecBlue.push_back(pixAux.getBlue());
            }

            if(img.estaEnLaImagen(fila-1,columna))
            {
                pixAux = img.getPixel(fila-1, columna);
                vecRed.push_back(pixAux.getRed());
                vecGreen.push_back(pixAux.getGreen());
                vecBlue.push_back(pixAux.getBlue());
            }

            if(img.estaEnLaImagen(fila-1,columna+1))
            {
                pixAux = img.getPixel(fila-1, columna+1);
                vecRed.push_back(pixAux.getRed());
                vecGreen.push_back(pixAux.getGreen());
                vecBlue.push_back(pixAux.getBlue());
            }

            if(img.estaEnLaImagen(fila,columna-1))
            {
                pixAux = img.getPixel(fila, columna-1);
                vecRed.push_back(pixAux.getRed());
                vecGreen.push_back(pixAux.getGreen());
                vecBlue.push_back(pixAux.getBlue());
            }

            if(img.estaEnLaImagen(fila,columna+1))
            {
                pixAux = img.getPixel(fila, columna+1);
                vecRed.push_back(pixAux.getRed());
                vecGreen.push_back(pixAux.getGreen());
                vecBlue.push_back(pixAux.getBlue());
            }

            if(img.estaEnLaImagen(fila+1,columna-1))
            {
                pixAux = img.getPixel(fila+1, columna-1);
                vecRed.push_back(pixAux.getRed());
                vecGreen.push_back(pixAux.getGreen());
                vecBlue.push_back(pixAux.getBlue());
            }

            if(img.estaEnLaImagen(fila+1,columna))
            {
                pixAux = img.getPixel(fila+1, columna);
                vecRed.push_back(pixAux.getRed());
                vecGreen.push_back(pixAux.getGreen());
                vecBlue.push_back(pixAux.getBlue());
            }

            if(img.estaEnLaImagen(fila+1,columna+1))
            {
                pixAux = img.getPixel(fila+1, columna+1);
                vecRed.push_back(pixAux.getRed());
                vecGreen.push_back(pixAux.getGreen());
                vecBlue.push_back(pixAux.getBlue());
            }

            sort(vecRed.begin(), vecRed.end());
            sort(vecGreen.begin(), vecGreen.end());
            sort(vecBlue.begin(), vecBlue.end());

            if(vecRed.size() % 2 == 0)
            {
                medio = vecRed.size()/2;
                auxRed = (vecRed[medio] + vecRed[medio+1])/2;
                auxGreen = (vecGreen[medio] + vecGreen[medio+1])/2;
                auxBlue = (vecBlue[medio] + vecBlue[medio+1])/2;
            }
            else
            {
                medio = (vecRed.size()/2)+1;
                auxRed = vecRed[medio];
                auxGreen = vecGreen[medio];
                auxBlue = vecBlue[medio];
            }

            pixAux.setPixelRGB(auxRed, auxGreen, auxBlue);
            imagen.setPixel(pixAux, fila, columna);

            vecRed.clear();
            vecGreen.clear();
            vecBlue.clear();
        }
    }

    return imagen;
}

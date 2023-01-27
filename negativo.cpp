#include "negativo.h"

Negativo::Negativo()
{

}

Imagen Negativo::aplicarFiltro(Imagen &img)
{
    Imagen imagen = img;
    unsigned int auxRed, auxGreen, auxBlue;
    Pixel pixelAux;

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();

    for (int f=0; f<nFilas; f++)
    {
        for (int c=0; c<nColumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            auxRed = img.getRango() - pixelAux.getRed();
            auxGreen = img.getRango() - pixelAux.getGreen();
            auxBlue = img.getRango() - pixelAux.getBlue();

            if (img.getIdentificador() == "P1" or img.getIdentificador() == "P4")
                pixelAux.setPixelMono(auxRed);
            else
                pixelAux.setPixelRGB(auxRed,auxGreen,auxBlue);

            imagen.setPixel(pixelAux, f, c);
        }
    }

    return imagen;
}


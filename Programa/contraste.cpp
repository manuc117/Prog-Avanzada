#include "contraste.h"

Contraste::Contraste()
{

}

Imagen Contraste::procesarImagen(Imagen &img)
{
    ProcesadorEstadistico proEst;
    Imagen imagen = img;
    unsigned int auxRed, auxGreen, auxBlue;

    int nFilas = img.getFilas(), nColumnas = img.getColumnas();
    Pixel pixelAux;
    int minR=proEst.getMinimoR(img), minG=proEst.getMinimoG(img), minB=proEst.getMinimoB(img), maxR=proEst.getMaximoR(img), maxG=proEst.getMaximoG(img), maxB=proEst.getMaximoB(img);
    int rango = img.getRango();

    for (int f=0; f<nFilas; f++)
    {
        for(int c=0; c<nColumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            auxRed = (((float)pixelAux.getRed()-(float)minR)/((float)maxR-(float)minR))*rango;
            auxGreen = (((float)pixelAux.getGreen()-(float)minG)/((float)maxG-(float)minG))*rango;
            auxBlue = (((float)pixelAux.getBlue()-(float)minB)/((float)maxB-(float)minB))*rango;

            if (img.getIdentificador() == "P1" or img.getIdentificador() == "P4")
                pixelAux.setPixelMono(auxRed);
            else
                pixelAux.setPixelRGB(auxRed,auxGreen,auxBlue);

            imagen.setPixel(pixelAux, f, c);
        }
    }

    return imagen;
}

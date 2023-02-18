/*!
 *  \class      Pixel
 *  \brief      Clase que forma un pixel de una imagen.
 *  \details    Representa el pixel de cualquier tipo de imagen (RGB, de intensidades
 *              o monocromática). Posee valores enteros de rojo, verde y azul, los cuales
 *              puede devolver. Además puede calcular la intensidad del pixel a partir
 *              de estos tres valores.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:

    Pixel();

    Pixel(int r, int g, int b);

    int getRed();

    int getGreen();

    int getBlue();

    void setRed(int r);

    void setGreen(int g);

    void setBlue(int b);

    void setPixelRGB(int r, int g=-1, int b=-1);

    void setPixelMono(int valor);

    int getIntensidad();

private:

    int red, green, blue;

};

#endif // PIXEL_H

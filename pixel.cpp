#include "pixel.h"

Pixel::Pixel()
{

}

Pixel::Pixel(int r, int g, int b)
{
    red = r;
    green = g;
    blue = b;
}

int Pixel::getRed()
{
    return red;
}

int Pixel::getGreen()
{
    return green;
}

int Pixel::getBlue()
{
    return blue;
}

void Pixel::setRed(int r)
{
    red = r;
}

void Pixel::setGreen(int g)
{
    green = g;
}

void Pixel::setBlue(int b)
{
    blue = b;
}

void Pixel::setPixelRGB(int r, int g, int b)
{
    if (g != -1 and b != -1)
    {
        red = r;
        green = g;
        blue = b;
    }
    else
    {
        red = r;
        green = r;
        blue = r;
    }
}

void Pixel::setPixelMono(int valor)
{
    if (valor == 0)
    {
        red = 1;
        green = 1;
        blue = 1;
    }
    else
    {
        red = 0;
        green = 0;
        blue = 0;
    }
}

int Pixel::getIntensidad()
{
    return ((red+green+blue)/3);
}


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

private:

    int red;
    int green;
    int blue;
};

#endif // PIXEL_H

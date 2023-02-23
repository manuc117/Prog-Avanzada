#include "binarizado.h"

Binarizado::Binarizado()
{

}

Imagen Binarizado::aplicarFiltro(Imagen &img)
{
    if(sePuedeBinarizar(img))
    {
        int nivel = getNivelBinarizacion(img);
        int nFilas = img.getFilas(), nColumnas = img.getColumnas(), rango = img.getRango();

        for (int f=0; f<nFilas; f++)
        {
            for(int c=0; c<nColumnas; c++)
            {
                if(img.getPixel(f,c).getIntensidad() >= nivel)
                    img.setPixel(Pixel(rango,rango,rango), f, c);
                else
                    img.setPixel(Pixel(0,0,0), f, c);
            }
        }
    }
    else
    {
        cout<<"La imagen no se puede binarizar.\n";
        cout.flush();
    }

    return img;
}

bool Binarizado::sePuedeBinarizar(Imagen &img)
{
    return(img.getIdentificador() == "P2" or img.getIdentificador() == "P5" or img.getIdentificador() == "P2C");
}

int Binarizado::getNivelBinarizacion(Imagen &img)
{
    int nivel;
    cout<<"Insertar el nivel a partir del cual se quiere binarizar la imagen entre [0,"<<img.getRango()<<"]: ";
    cin>>nivel;

    while(nivel <= 0 or nivel >= img.getRango() or !cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Ingrese una opcion valida entre [0,"<<img.getRango()<<"]: ";
        cout.flush();
        cin>>nivel;
        cout<<endl;
    }

    return nivel;
}

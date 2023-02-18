#include "brillo.h"

Brillo::Brillo(int opcion)
{
    if (opcion == 1)
        operacion = 'a';
    else if (opcion == 2)
        operacion = 'r';
}

Imagen Brillo::aplicarFiltro(Imagen &img)
{
    if (operacion == 'a')
        aumentarBrillo(img);
    else if(operacion == 'r')
        reducirBrillo(img);

    return img;
}

void Brillo::aumentarBrillo(Imagen &img)
{
    getValor(img);
    Pixel pixelAux;
    int auxRed, auxGreen, auxBlue;
    int nFilas = img.getFilas(), nColumnas = img.getColumnas(), rango = img.getRango();

    for(int f=0; f<nFilas; f++)
    {
        for(int c=0; c<nColumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            auxRed = pixelAux.getRed() + valor;
            if(auxRed > rango)
                auxRed = rango;

            auxGreen = pixelAux.getGreen() + valor;
            if(auxGreen > rango)
                auxGreen = rango;

            auxBlue = pixelAux.getBlue() + valor;
            if(auxBlue > rango)
                auxBlue = rango;

            if (img.getIdentificador() == "P1" or img.getIdentificador() == "P4")
                pixelAux.setPixelMono(auxRed);
            else
                pixelAux.setPixelRGB(auxRed,auxGreen,auxBlue);

            img.setPixel(pixelAux, f, c);
        }
    }
}

void Brillo::reducirBrillo(Imagen &img)
{
    getValor(img);
    Pixel pixelAux;
    int auxRed, auxGreen, auxBlue;
    int nFilas = img.getFilas(), nColumnas = img.getColumnas(), rango = img.getRango();

    for(int f=0; f<nFilas; f++)
    {
        for(int c=0; c<nColumnas; c++)
        {
            pixelAux = img.getPixel(f,c);

            auxRed = pixelAux.getRed() - valor;
            if(auxRed < 0)
                auxRed = 0;

            auxGreen = pixelAux.getGreen() - valor;
            if(auxGreen < 0)
                auxGreen = 0;

            auxBlue = pixelAux.getBlue() - valor;
            if(auxBlue < 0)
                auxBlue = 0;

            if (img.getIdentificador() == "P1" or img.getIdentificador() == "P4")
                pixelAux.setPixelMono(auxRed);
            else
                pixelAux.setPixelRGB(auxRed,auxGreen,auxBlue);

            img.setPixel(pixelAux, f, c);
        }
    }
}

void Brillo::getValor(Imagen &img)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    char elegir;

    cout<<"¿Desea especificar cuanto aumentar/reducir el brillo o usar un valor por defecto?\n";
    cout<<"\t-> [e] para ELEGIR VALOR"<<endl;
    cout<<"\t-> [d] para VALOR POR DEFECTO"<<endl<<endl;
    cout<<"Ingrese una opcion: ";
    cin>>elegir;
    elegir = tolower(elegir);
    cout<<endl;

    while (elegir != 'e' and elegir != 'd')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Seleccione un opcion valida: ";
        cin>>elegir;
        elegir = tolower(elegir);
    }

    if(elegir == 'd')
    {
        valor = 50;
    }
    else if(elegir == 'e')
    {
        valor = -1;
        while(valor < 0 or valor > img.getRango() or !cin.good())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout<<"Ingrese un valor entre [0,"<<img.getRango()<<"]: ";
            cout.flush();
            cin>>valor;
            cout<<endl;
        }
    }
}


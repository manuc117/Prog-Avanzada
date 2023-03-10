#include "algoritmodelpintor.h"

AlgoritmoDelPintor::AlgoritmoDelPintor()
{

}

Imagen AlgoritmoDelPintor::aplicarAlgoritmo(int fInicial, int cInicial, Imagen &imagen)
{
    Pixel pixelInicial = imagen.getPixel(fInicial, cInicial);

    inicializarMatriz(imagen.getFilas(), imagen.getColumnas());

    unsigned int rangoTolerancia = getRangoDeTolerancia(imagen.getRango());

    profundidad = 0;

    contadorPixeles = 0;

    pintarVecinos(fInicial, cInicial, pixelInicial, rangoTolerancia, imagen);

    cout<<"\tPixeles pintados: "<<contadorPixeles;

    return imagen;
}

void AlgoritmoDelPintor::inicializarMatriz(int filas, int columnas)
{
    vector<vector<bool>> matriz(filas, vector<bool> (columnas, false));

    matrizAnalisis = matriz;
}

void AlgoritmoDelPintor::pintarVecinos(int fila, int columna, Pixel pixReferencia, unsigned int tolerancia, Imagen &imagen)
{
    ++profundidad;

    if(imagen.estaEnLaImagen(fila,columna))
    {
        if(esVecino(pixReferencia, imagen.getPixel(fila, columna), tolerancia) and profundidad < 11000)
        {
            if(!matrizAnalisis[fila][columna])
            {
                matrizAnalisis[fila][columna] = true;

                for(int vecino=0; vecino<8; vecino++)
                {
                   pintarVecinos(fila+vecinosF[vecino], columna+vecinosC[vecino], pixReferencia, tolerancia, imagen);
                }

                imagen.setPixel(Pixel(0,0,255), fila, columna);

                ++contadorPixeles;
            }
        }
    }

    --profundidad;
}

bool AlgoritmoDelPintor::esVecino(Pixel pixReferencia, Pixel pixAnalisis, unsigned int tolerancia)
{
    bool rEs = pixAnalisis.getRed() <= pixReferencia.getRed()+(int(tolerancia)) and pixAnalisis.getRed() >= pixReferencia.getRed()-(int(tolerancia));
    bool gEs = pixAnalisis.getGreen() <= pixReferencia.getGreen()+(int(tolerancia)) and pixAnalisis.getGreen() >= pixReferencia.getGreen()-(int(tolerancia));
    bool bEs = pixAnalisis.getBlue() <= pixReferencia.getBlue()+(int(tolerancia)) and pixAnalisis.getBlue() >= pixReferencia.getBlue()-(int(tolerancia));

    return (rEs and gEs and bEs);
}

unsigned int AlgoritmoDelPintor::getRangoDeTolerancia(int maxRango)
{
    int tolerancia;

    cout<<"\n\tIngrese el rango de tolerancia a considerar entre [0,"<<maxRango<<"]: ";
    cin>>tolerancia;

    while(tolerancia < 0 or tolerancia > maxRango or !cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"\tIngrese un rango de tolerancia valido entre [0,"<<maxRango<<"]: ";
        cin>>tolerancia;
    }

    return tolerancia/2;
}


#include "algoritmodelpintor.h"

AlgoritmoDelPintor::AlgoritmoDelPintor(Imagen &img)
{
    imagen = img;
}

Imagen AlgoritmoDelPintor::aplicarAlgoritmo(int fInicial, int cInicial)
{
    Pixel pixelInicial = imagen.getPixel(fInicial, cInicial);

    inicializarMatriz(fInicial, cInicial);

    unsigned int rangoTolerancia = getRangoDeTolerancia(imagen.getRango());

    pintarVecinos(fInicial, cInicial, pixelInicial, rangoTolerancia);

    return imagen;
}

void AlgoritmoDelPintor::inicializarMatriz(int fila, int columna)
{
    vector<vector<bool>> matriz(fila, vector<bool> (columna, false));

    matrizAnalisis = matriz;
}

void AlgoritmoDelPintor::pintarVecinos(int fila, int columna, Pixel pixReferencia, unsigned int tolerancia)
{
    if(imagen.estaEnLaImagen(fila,columna))
    {
        if(esVecino(pixReferencia, imagen.getPixel(fila, columna), tolerancia))
        {
            if(!matrizAnalisis[fila][columna])
            {
                matrizAnalisis[fila][columna] = true;

                for(int vecino=0; vecino<8; vecino++)
                {
                   pintarVecinos(fila+vecinosF[vecino], columna+vecinosC[vecino], pixReferencia, tolerancia);
                }

                imagen.setPixel(Pixel(255,0,0), fila, columna);
            }
        }
    }
}

bool AlgoritmoDelPintor::esVecino(Pixel pixReferencia, Pixel pixAnalisis, unsigned int tolerancia)
{
    return(pixAnalisis.getRed()<=pixReferencia.getRed()+tolerancia/2 and pixAnalisis.getRed()>=pixReferencia.getRed()-tolerancia/2 and pixAnalisis.getGreen()<=pixReferencia.getGreen()+tolerancia/2 and pixAnalisis.getGreen()>=pixReferencia.getGreen()-tolerancia/2 and pixAnalisis.getBlue()<=pixReferencia.getBlue()+tolerancia/2 and pixAnalisis.getBlue()>=pixReferencia.getBlue()-tolerancia/2);
}

unsigned int AlgoritmoDelPintor::getRangoDeTolerancia(int maxRango)
{
    int tolerancia;

    cout<<"Ingrese el rango de tolerancia a considerar entre [0,"<<maxRango<<"]: ";
    cin>>tolerancia;

    while(tolerancia < 0 or tolerancia > maxRango or !cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Ingrese un rango de tolerancia valido entre [0,"<<maxRango<<"]";
        cin>>tolerancia;
    }

    return tolerancia;
}


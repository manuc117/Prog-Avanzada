#include "lut.h"

LUT::LUT(int opcion)
{
    cargarTabla(opcion);
}

Pixel LUT::pseudocolorear(int intensidad)
{
    Pixel pixelColoreado(tabla[intensidad][1],tabla[intensidad][2],tabla[intensidad][3]);

    return pixelColoreado;
}

void LUT::cargarTabla(int opcion)
{
    tabla.resize(256);
    for(int f=0; f<tabla.size(); f++)
        tabla[f].resize(4);

    fstream archiLut;
    archiLut.open(grupoLuts[opcion-1], ios::in);

    string titulos;
    getline(archiLut, titulos);

    for(int f=0; f<tabla.size(); f++)
        archiLut>>tabla[f][0]>>tabla[f][1]>>tabla[f][2]>>tabla[f][3];

}


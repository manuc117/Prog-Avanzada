#include "archivoaic.h"

ArchivoAIC::ArchivoAIC()
{

}

Imagen ArchivoAIC::leer(string ruta)
{
    ifstream archi;
    Imagen img;

    archi.open(ruta, ios::in);

    if(archi.is_open())
    {
        string linea;

        getline(archi, linea);
        img.setIdentificador(linea);
    }
    else
    {
        cout<<"Error al abrir el archivo "<<ruta<<".";
        cout.flush();
    }

    return img;
}

void ArchivoAIC::guardar(Imagen *img)
{

}

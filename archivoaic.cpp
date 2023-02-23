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
        int nColumnas, nFilas;

        getline(archi, linea);
        img.setIdentificador(linea);

        int posicion;

        while(true)
        {
            getline(archi, linea);

            if (linea[0] == '#' or linea == "")
                img.setComentario(linea);
            else
            {
                posicion = linea.find_first_of(' ');
                nColumnas = stoi(linea.substr(0,posicion));
                nFilas = stoi(linea.substr(posicion));
                break;
            }
        }

        if(nColumnas == 0 or nFilas == 0)
            throw ExcepcionArchivoCorrupto();

        img.setColumnas(nColumnas);
        img.setFilas(nFilas);
        img.setTamanio();

        int rangoAux;
        archi>>rangoAux;
        img.setRango(rangoAux);

        string espacio;
        getline(archi, espacio);

        int nivelGris, repeticiones, contadorCol;

        Pixel pixelAux;

        int contadorPixeles = 0;

        for(int f=0; f<img.getFilas(); f++)
        {
            getline(archi, linea);
            vector<int> datos = lineaAVector(linea);

            repeticiones = 0;
            contadorCol = 0;

            for(int i=0; i<datos.size(); i=i+2)
            {
                nivelGris = datos.at(i);

                if(nivelGris > img.getRango())
                    throw ExcepcionArchivoCorrupto();

                repeticiones = datos.at(i+1);
                pixelAux.setPixelRGB(nivelGris, nivelGris, nivelGris);

                for(int c=0; c<repeticiones; c++)
                {
                    img.setPixel(pixelAux, f, c+contadorCol);
                    contadorPixeles++;
                }

                contadorCol += repeticiones;
                repeticiones = 0;
            }
        }

        if (contadorPixeles != img.getColumnas()*img.getFilas())
            throw ExcepcionArchivoCorrupto();

        almacenarUltimaRuta(ruta);
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
    ofstream archi;

    string nombreGuardado;
    cout<<"Ingrese un nombre para la imagen que desea guardar: ";
    cin>>nombreGuardado;

    string rutaNueva = "./Imagenes/imagenes_guardadas/"+nombreGuardado+".aic";

    archi.open(rutaNueva);

    if(archi.is_open())
    {
        archi<<"P2C"<<"\n";
        archi<<img->getComentario()<<"\n";
        archi<<img->getColumnas()<<" "<<img->getFilas()<<"\n";
        archi<<img->getRango()<<"\n";

        int nColumnas = img->getColumnas(), nFilas = img->getFilas();
        int nivelGris, repeticiones, nivelAnterior;

        for(int f=0; f<nFilas; f++)
        {
            repeticiones = 0;
            nivelAnterior = img->getPixel(f,0).getRed();

            for(int c=0; c<nColumnas; c++)
            {
                if (img->getPixel(f, c).getIntensidad() != nivelAnterior)
                {
                    archi<<nivelGris<<" "<<repeticiones<<" ";
                    repeticiones = 1;
                    nivelGris = img->getPixel(f,c).getIntensidad();
                    nivelAnterior = nivelGris;

                }
                else
                {
                    repeticiones += 1;
                    nivelGris = img->getPixel(f,c).getIntensidad();

                }
            }
            archi<<nivelGris<<" "<<repeticiones<<" ";
            archi<<"\n";
        }

    }
    else
    {
        cout<<"Error al abrir el archivo "<<rutaNueva<<".";
        cout.flush();
    }

    archi.close();
}

void ArchivoAIC::almacenarUltimaRuta(string ruta)
{
    ofstream registro;

    registro.open("registro.txt");

    registro<<ruta;
}

vector<int> ArchivoAIC::lineaAVector(string linea)
{
    vector<int> datos;

    string aux = "";

    for(int i = 0; i<linea.length(); i++)
    {
        if(linea[i] != ' ' and linea[i] != '\n')
        {
            aux += linea[i];
        }
        else
        {
            datos.push_back(stoi(aux));
            aux = "";
        }
    }

    return datos;
}



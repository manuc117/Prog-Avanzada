#include "archivopnm.h"

ArchivoPNM::ArchivoPNM()
{

}

Imagen ArchivoPNM::leer(string ruta)
{
    ifstream archi;
    Imagen img;

    archi.open(ruta);

    if (archi.is_open())
    {
        string linea;
        int ncolumnas, nfilas;

        //Lectura codigo de identificación
        getline(archi, linea);
        img.setIdentificador(linea);

        //Leer comentarios que empiezan con # y terminan con \n o \n\r
        int posicion = archi.tellg();

        while(true)
        {
            posicion = archi.tellg();
            getline(archi, linea);

            if (linea[0] == '#')
                img.setComentario(linea);
            else
                break;
        }

        //Lectura columnas y filas
        archi.seekg(posicion);

        archi>>ncolumnas>>nfilas;
        img.setColumnas(ncolumnas);
        img.setFilas(nfilas);
        img.setTamanio();

        //Lectura del rango
        if(img.getIdentificador()[1]!=1 and img.getIdentificador()[1]!=4)
        {
            int rangoAux;
            archi>>rangoAux;
            img.setRango(rangoAux);
        }

        //Lectura de pixeles (datos)
        Pixel pixelAux;
        unsigned char r, g, b;
        int intensidad;

        switch(img.getIdentificador()[1])
        {
            case '1':
                img.setRango(1);

                for (int fila=0; fila<nfilas; fila++)
                {
                    for (int columna=0; columna<ncolumnas; columna++)
                    {
                        archi>>intensidad;
                        pixelAux.setPixelMono((int)intensidad);
                        img.setPixel(pixelAux, fila, columna);
                    }
                }
                archi.close();
                break;

            case '2':
                for (int fila=0; fila<nfilas; fila++)
                {
                    for (int columna=0; columna<ncolumnas; columna++)
                    {
                        archi>>intensidad;
                        pixelAux.setPixelRGB((int)intensidad);
                        img.setPixel(pixelAux, fila, columna);
                    }
                }
                archi.close();
                break;

            case '3':
                int R, G, B;

                for(int fila=0; fila<nfilas; fila++)
                {
                    for(int columna=0; columna<ncolumnas; columna++)
                    {
                        archi>>R>>G>>B;
                        pixelAux.setPixelRGB(R, G, B);
                        img.setPixel(pixelAux, fila, columna);
                    }
                }
                archi.close();
                break;

            case '4':
                img.setRango(1);
                posicion = archi.tellg();
                archi.close();

                archi.open(ruta, ios::binary | ios::in);
                archi.seekg(posicion);

                for (int fila=0; fila<nfilas; fila++)
                {
                    for (int columna=0; columna<ncolumnas; columna++)
                    {
                        archi.read((char*)&r, sizeof(r));
                        intensidad = (int)r;
                        pixelAux.setPixelMono((int)intensidad);
                        img.setPixel(pixelAux, fila, columna);

                    }
                }
                archi.close();
                break;

            case '5':
                getline(archi, linea, '\n');
                posicion = archi.tellg();
                archi.close();

                archi.open(ruta, ios::binary | ios::in);
                archi.seekg(posicion);

                for (int fila=0; fila<nfilas; fila++)
                {
                    for (int columna=0; columna<ncolumnas; columna++)
                    {
                        archi.read((char*)&r, sizeof(r));
                        intensidad = (int)r;
                        pixelAux.setPixelRGB(intensidad);
                        img.setPixel(pixelAux, fila, columna);

                    }
                }
                archi.close();
                break;

            case '6':
                getline(archi, linea, '\n');
                posicion = archi.tellg();
                archi.close();

                archi.open(ruta, ios::binary | ios::in);
                archi.seekg(posicion);

                for(int fila=0; fila<nfilas; fila++)
                {
                    for(int columna=0; columna<ncolumnas; columna++)
                    {
                        archi.read((char*)&r, sizeof(r));
                        archi.read((char*)&g, sizeof(g));
                        archi.read((char*)&b, sizeof(b));

                        pixelAux.setPixelRGB((int) r, (int) g, (int) b); //casteo xq tengo que recibir un int y lei un unsigned char.
                        img.setPixel(pixelAux, fila, columna);
                    }
                }
                archi.close();
                break;
        }
    }
    else
    {
        cout<<"Error al abrir el archivo "<<ruta<<".";
        cout.flush(); //para que se imprima lo del cout anterior si o si
    }

        return img;
}

void ArchivoPNM::guardar(Imagen *img)
{
    ofstream archi;

    string nombreGuardado;
    cout<<"Ingrese un nombre para la imagen que desea guardar: ";
    cin>>nombreGuardado;

    string rutaNueva = "./Imagenes/imagenes_guardadas/"+nombreGuardado+getExtension(img->getIdentificador());

    archi.open(rutaNueva);

    if (archi.is_open())
    {
        archi<<img->getIdentificador()<<"\n";
        archi<<img->getComentario()<<"\n";
        archi<<img->getColumnas()<<" "<<img->getFilas();
        archi<<img->getRango()<<endl;

        Pixel pixelAux;
        unsigned char nivelIntens;
        int intensidad;
        int nfilas=img->getFilas(), ncolumnas=img->getColumnas();

        switch(img->getIdentificador()[1])
        {
            case '1':
                for (int fila=0; fila<nfilas; fila++)
                {
                    for (int columna=0; columna<ncolumnas; columna++)
                    {
                        pixelAux = img->getPixel(fila,columna);
                        intensidad = pixelAux.getRed();
                        if (intensidad == 0)
                            intensidad = 1;
                        else if(intensidad == 1)
                            intensidad = 0;
                        archi<<intensidad<<" ";
                    }
                    archi<<endl;
                }
                archi.close();
                break;

            case '2':
                for (int fila=0; fila<nfilas; fila++)
                {
                    for (int columna=0; columna<ncolumnas; columna++)
                    {
                        pixelAux = img->getPixel(fila,columna);
                        intensidad = pixelAux.getRed();
                        archi<<intensidad<<" ";
                    }
                    archi<<endl;
                }
                archi.close();
                break;

            case '3':
                int R, G, B;

                for(int fila=0; fila<nfilas; fila++)
                {
                    for(int columna=0; columna<ncolumnas; columna++)
                    {
                        pixelAux = img->getPixel(fila,columna);
                        R = pixelAux.getRed();
                        G = pixelAux.getGreen();
                        B = pixelAux.getBlue();
                        archi<<R<<G<<B;
                    }
                    archi<<endl;
                }
                archi.close();
                break;

            case '4':
                archi.close();
                archi.open(rutaNueva, ios::binary | ios::out | ios::app);

                for (int fila=0; fila<nfilas; fila++)
                {
                    for (int columna=0; columna<ncolumnas; columna++)
                    {
                        pixelAux = img->getPixel(fila,columna);
                        nivelIntens = (unsigned char)pixelAux.getRed();
                        archi.write((char*)&nivelIntens, sizeof(nivelIntens));
                    }
                }
                archi.close();
                break;

            case '5':
                archi.close();
                archi.open(rutaNueva, ios::binary | ios::out | ios::app);

                for (int fila=0; fila<nfilas; fila++)
                {
                    for (int columna=0; columna<ncolumnas; columna++)
                    {
                        pixelAux = img->getPixel(fila,columna);
                        nivelIntens = (unsigned char)pixelAux.getRed();
                        archi.write((char*)&nivelIntens, sizeof(nivelIntens));
                    }
                }
                archi.close();
                break;

            case '6':
                archi.close();
                archi.open(rutaNueva, ios::binary | ios::out | ios::app);

                unsigned char r, g, b;

                for(int fila=0; fila<nfilas; fila++)
                {
                    for(int columna=0; columna<ncolumnas; columna++)
                    {
                        pixelAux = img->getPixel(fila, columna);

                        r = (unsigned char) pixelAux.getRed();
                        g = (unsigned char) pixelAux.getGreen();
                        b = (unsigned char) pixelAux.getBlue();

                        archi.write((char*)&r, sizeof(r));
                        archi.write((char*)&g, sizeof(g));
                        archi.write((char*)&b, sizeof(b));
                    }
                }
                archi.close();
                break;
        }
    }
    else
    {
        cout<<"Error al abrir el archivo "<<rutaNueva<<".";
        cout.flush();
    }
}

string ArchivoPNM::getExtension(string identificador)
{
    string extension;

    if(identificador == "P1" or identificador == "P4" )
        extension = ".pbm";
    else
    {
        if(identificador == "P2" or identificador == "P5" or identificador == "P2C")
            extension = ".pgm";
        else if(identificador == "P3" or identificador == "P6")
            extension = ".ppm";
    }

    return extension;
}



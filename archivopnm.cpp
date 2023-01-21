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
     //archi>>linea;

     img.setIdentificador(linea);

     //Leer comentarios que empiezan con # y terminan con \n o \n\r
     int posicion = archi.tellg();

     while(true)
     {
         posicion = archi.tellg();

         getline(archi, linea);

         if (linea[0] == '#')
         {
           img.setComentario(linea);
         }
         else
         {
           break;
         }

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
     cout<<"Error al abrir el archivo.\n";
     cout<<ruta;
     cout.flush(); //para que se imprima lo del cout anterior si o si
  }

    return img;

}



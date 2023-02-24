#include "espaciodetrabajo.h"

EspacioDeTrabajo::EspacioDeTrabajo()
{

}

vector<string> EspacioDeTrabajo::getCarpetas()
{
    return carpetas;
}

vector<string> EspacioDeTrabajo::getNombreArchivos(string rutaDir)
{
    vector<string> lista_de_archivos;

    DIR *dir = opendir(rutaDir.c_str());
    if (dir != NULL)
    {
        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {
            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                lista_de_archivos.push_back(entry->d_name);
            }
        }
        closedir(dir);
     }

    return lista_de_archivos;
}

string EspacioDeTrabajo::getRutaCarpeta(int carpetaSeleccionada)
{
    return "./Imagenes/"+carpetas[carpetaSeleccionada]+"/";
}

string EspacioDeTrabajo::getRutaArchivo(int carpetaSeleccionada, int archivoSeleccionado)
{
    return "./Imagenes/"+carpetas[carpetaSeleccionada]+"/"+getNombreArchivos(getRutaCarpeta(carpetaSeleccionada))[archivoSeleccionado];
}

bool EspacioDeTrabajo::esPNM(string rutaArchi)
{
    int pos = rutaArchi.find_last_of(".");
    string extension = rutaArchi.substr(pos);
    return extension == ".pbm" or extension == ".pgm" or extension == ".pnm" or extension == ".ppm";
}

bool EspacioDeTrabajo::esAIC(string rutaArchi)
{
    int pos = rutaArchi.find_last_of(".");
    string extension = rutaArchi.substr(pos);
    return extension == ".aic";
}

void EspacioDeTrabajo::guardarImagen(Imagen *img)
{
    bool seGuarda = true;

    char formatoGuardado;
    cout<<"Seleccione el formato de guardado de la imagen"<<endl;
    cout<<"\t-> [p] para pnm"<<endl;
    cout<<"\t-> [a] para aic"<<endl;
    cout<<"Formato: ";
    cin>>formatoGuardado;

    formatoGuardado = tolower(formatoGuardado);

    while (formatoGuardado != 'p' and formatoGuardado != 'a')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Seleccione un opcion valida: ";
        cin>>formatoGuardado;
        formatoGuardado = tolower(formatoGuardado);
    }

    char cambioFormato;

    if(formatoGuardado == 'a' and img->getIdentificador() != "P2" and img->getIdentificador() != "P2C" and img->getIdentificador() != "P5")
    {
        cout<<"\nEsta imagen no puede ser guardada en formato AIC."<<endl;
        cout<<"¿Desea almacenarla en fotmato PNM?"<<endl;
        cout<<"\t-> [s] para SI"<<endl;
        cout<<"\t-> [n] para NO"<<endl<<endl;
        cout<<"Cambiar formato: ";
        cin>>cambioFormato;
        cambioFormato = tolower(cambioFormato);

        while (cambioFormato != 's' and cambioFormato != 'n')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout<<"Seleccione un opcion valida: ";
            cin>>cambioFormato;
            cambioFormato = tolower(cambioFormato);
        }

        if (cambioFormato == 's')
            formatoGuardado = 'p';
        else
        {
            cout<<"No se pudo guardar el archivo.";
            seGuarda = false;
            cout.flush();
        }
    }

    if (seGuarda)
    {
        GestorDeArchivo *archivo;

        if (formatoGuardado == 'p')
        {
            archivo = new ArchivoPNM;
            archivo->guardar(img);
        }
        else
        {
            archivo = new ArchivoAIC;
            archivo->guardar(img);
        }
    }
}








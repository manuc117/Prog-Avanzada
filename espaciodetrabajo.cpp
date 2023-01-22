#include "espaciodetrabajo.h"

EspacioDeTrabajo::EspacioDeTrabajo()
{

}

vector<string> EspacioDeTrabajo::getCarpetas()
{
    return carpetas;
}

vector<string> EspacioDeTrabajo::getNombreArchivos(int carpetaSeleccionada)
{
    vector<string> lista_de_archivos;

    string pRutaDirectorio = "./Imagenes/"+carpetas[carpetaSeleccionada]+"/";

    DIR *dir = opendir(pRutaDirectorio.c_str());
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

string EspacioDeTrabajo::getRutaArchivo(int carpetaSeleccionada, int archivoSeleccionado)
{
    return "./Imagenes/"+carpetas[carpetaSeleccionada]+"/"+getNombreArchivos(carpetaSeleccionada)[archivoSeleccionado];
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






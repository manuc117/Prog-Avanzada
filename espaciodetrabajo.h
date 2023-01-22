#ifndef ESPACIODETRABAJO_H
#define ESPACIODETRABAJO_H

#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>

using namespace std;

class EspacioDeTrabajo
{
public:
    EspacioDeTrabajo();

    vector<string> getCarpetas();

    vector<string> getNombreArchivos(int carpetaSeleccionada);

    string getRutaArchivo(int carpetaSeleccionada, int archivoSeleccionado);

    bool esPNM(string rutaArchi);

    bool esAIC(string rutaArchi);



private:

    const vector<string> carpetas =
    {
        "grupo_imagenes_1",
        "grupo_imagenes_2",
        "grupo_imagenes_3_corruptas",
        "imagenes_guardadas"
    };

};

#endif // ESPACIODETRABAJO_H

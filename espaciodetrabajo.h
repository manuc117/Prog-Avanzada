#ifndef ESPACIODETRABAJO_H
#define ESPACIODETRABAJO_H

#include "imagen.h"
#include "gestordearchivos.h"
#include "archivopnm.h"
#include "archivoaic.h"

#include <vector>
#include <string>
#include <dirent.h>
#include <iostream>
#include <limits>

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

    void guardarImagen(Imagen *img);

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

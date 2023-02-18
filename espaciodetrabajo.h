/*!
 *  \class      EspacioDeTrabajo
 *  \brief      Clase capaz de administrar donde se ecuentran almacenados los archivos.
 *  \details    Conoce las carpetas y la raiz de la ruta. Puede obtener el nombre de los
 *              archivos presentes en una carpeta y almacenarlos en la memoria. También es
 *              capaz de devolver la ruta de un archivo en particular a partir de el nombre
 *              del archivo y de la carpeta en la que se encuentra este. Gestiona el guardado
 *              de imagenes.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
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
        "ij_image_samples",
        "imagenes_guardadas"
    };
};

#endif // ESPACIODETRABAJO_H

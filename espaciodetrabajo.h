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
    /*!
     * \brief EspacioDeTrabajo Constructor del objeto EspacioDeTrabajo.
     */
    EspacioDeTrabajo();

    /*!
     * \brief getCarpetas Método que permite obtener la lista de carpetas conocidas por
     *        el espacio de trabajo.
     * \return Vector de strings, la lista de carpetas conocidas por el espacio de
     *         trabajo.
     */
    vector<string> getCarpetas();

    /*!
     * \brief getNombreArchivos Método que permite obtener la lista de archivos presentes
     *        en una carpeta.
     * \param[in] carpetaSeleccionada Opción de carpeta seleccionada por el usuario.
     * \return Vector de strings, la lista de archivos presentes en una carpeta.
     */
    vector<string> getNombreArchivos(int carpetaSeleccionada);

    /*!
     * \brief getRutaArchivo Método que permite devolver la ruta de un archivo a partir de
     *        una opción de carpeta y una opción de archivo.
     * \param[in] carpetaSeleccionada Opción de la carpeta seleccionada por el usuario.
     * \param[in] archivoSeleccionado Opción del archivo seleccionado por el usuario.
     * \return Ruta correspondiente a un archivo.
     */
    string getRutaArchivo(int carpetaSeleccionada, int archivoSeleccionado);

    /*!
     * \brief esPNM Método que devuelve si un archivo es PNM o no.
     * \param[in] rutaArchi Ruta del archivo analizado.
     * \return Booleano que indica que un archivo es PNM cuando su valor es true
     *         y que no lo es cuando su valor es false.
     */
    bool esPNM(string rutaArchi);

    /*!
     * \brief esAIC Método que devuelve si un archivo es AIC o no.
     * \param[in] rutaArchi Ruta del archivo analizado.
     * \return Booleano que indica que un archivo es AIC cuando su valor es true
     *         y que no lo es cuando su valor es false.
     */
    bool esAIC(string rutaArchi);

    /*!
     * \brief guardarImagen Método auxiliar en el guardado de una imagen.
     * \param[in] img Imagen a guardar.
     */
    void guardarImagen(Imagen *img);

private:

    /*!
     * \param carpetas Lista de carpetas conocidas por el espacio de trabajo.
     */
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

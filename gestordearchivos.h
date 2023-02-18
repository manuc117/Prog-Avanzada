/*!
 *  \class      GestorDeArchivos
 *  \brief      Clase abstracta de la cuál heredan los métodos leer y guardar archivos, y almacenar
 *              la ruta del último archivo leído otras clases.
 *  \details    Virtualiza sus métodos leer archivos, guardar archivos y almacenar la ruta del último
 *              archivo leído para que luego sean utilizados por sus clases hijas. Sus métodos son virtuales
 *              puros.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef GESTORDEARCHIVOS_H
#define GESTORDEARCHIVOS_H

#include "imagen.h"
#include <string>

class GestorDeArchivos //clase abstracta, metodos virtuales puros, no se puede instanciar
{
public:

    virtual Imagen leer(string ruta) = 0;

    virtual void guardar(Imagen *img) = 0;

    virtual void almacenarUltimaRuta(string ruta) = 0;
};

#endif // GESTORDEARCHIVOS_H

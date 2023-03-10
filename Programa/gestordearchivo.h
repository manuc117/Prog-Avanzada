/*!
 *  \class      GestorDeArchivo
 *  \brief      Clase abstracta de la cuál heredan los métodos leer y guardar archivos, y almacenar
 *              la ruta del último archivo leí­do otras clases.
 *  \details    Virtualiza sus métodos leer archivos, guardar archivos y almacenar la ruta del último
 *              archivo leí­do para que luego sean utilizados por sus clases hijas. Sus métodos son virtuales
 *              puros.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef GESTORDEARCHIVO_H
#define GESTORDEARCHIVO_H

#include "imagen.h"
#include <string>

class GestorDeArchivo //clase abstracta, metodos virtuales puros, no se puede instanciar
{
public:
    /*!
     * \brief GestorDeArchivo Constructor del objeto GestorDeArchivo.
     */
    GestorDeArchivo();

    /*!
     * \brief leer Método virtual que al ser redefinido permite leer un archivo de una
     *        Imagen.
     * \param[in] ruta Ruta del archivo que se quiere leer.
     * \return Objeto del tipo Imagen que estaba almacenada en la ruta.
     */
    virtual Imagen leer(string ruta) = 0;

    /*!
     * \brief guardar Método virtual que al ser redefinido permite guardar una Imagen.
     * \param[in] img Puntero a un objeto Imagen, que es la imagen a guardar.
     */
    virtual void guardar(Imagen *img) = 0;

    /*!
     * \brief almacenarUltimaRuta Método virtual que al ser redefinido permite almacenar
     *        la ruta del último archivo leí­do.
     * \param[in] ruta Ruta del último archivo leí­do que se quiere almacenar.
     */
    virtual void almacenarUltimaRuta(string ruta) = 0;

    /*!
     * \brief ~GestorDeArchivo Destructor del objeto GestorDeArchivo;
     */
    virtual ~GestorDeArchivo();
};

#endif // GESTORDEARCHIVO_H

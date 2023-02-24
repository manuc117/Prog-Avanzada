/*!
 *  \class      ArchivoPNM
 *  \brief      Clase capaz de gestionar los diferentes tipos de archivos PNM.
 *  \details    Hereda de GestorDeArchivos los métodos leer y guardar archivos, y de almacenar
 *              la ruta del último archivo leído. Además, a partir del código de identificación
 *              de una imagen, puede obtener la extensión correspondiente.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H

#include "gestordearchivo.h"
#include "ExcepcionArchivoCorrupto.h"

#include <fstream>
#include <iostream>

using namespace std;

class ArchivoPNM: public GestorDeArchivo
{
public:
    /*!
     * \brief ArchivoPNM Constructor del objeto ArchivoPNM.
     */
    ArchivoPNM();

    /*!
     * \brief leer Método heredado de la clase GestorDeArchivos, redefinido para
     *        leer una Imagen de un archivo PNM.
     * \param[in] ruta String, es la ruta del archivo que se quiere leer.
     * \return Objeto del tipo Imagen.
     */
    Imagen leer(string ruta) override;

    /*!
     * \brief guardar Método heredado de la clase GestorDeArchivos, redefinido para
     *        guardar una Imagen de un archivo PNM.
     * \param[in] img Puntero a un objeto Imagen, que es la imagen a guardar.
     */
    void guardar(Imagen *img) override;

    /*!
     * \brief almacenarUltimaRuta Método heredado de la clase GestorDeArchivos, redefinido
     *        para almacenar una ruta de un archivo PNM.
     * \param[in] ruta String, es la ruta del último archivo leído que se quiere almacenar.
     */
    void almacenarUltimaRuta(string ruta) override;

private:
    /*!
     * \brief getExtension Método privado auxiliar para el guardado de un archivo PNM,
     *        que permite obtener la extension del archivo.
     * \param[in] identificador String, código de identificación de la imagen.
     * \return String, extensión del archivo a ser guardado.
     */
    string getExtension(string identificador);

};

#endif // ARCHIVOPNM_H

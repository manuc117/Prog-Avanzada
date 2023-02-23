/*!
 *  \class      ArchivoAIC
 *  \brief      Clase capaz de gestionar los archivos de tipo AIC.
 *  \details    Hereda de GestorDeArchivos los métodos leer y guardar archivos, y de almacenar
 *              la ruta del último archivo leído.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H

#include "gestordearchivos.h"
#include "ExcepcionArchivoCorrupto.h"

#include <fstream>
#include <iostream>

using namespace std;

class ArchivoAIC: public GestorDeArchivos
{
public:
    /*!
     * \brief ArchivoAIC Constructor del objeto ArchivoAIC.
     */
    ArchivoAIC();

    /*!
     * \brief leer Método heredado de la clase GestorDeArchivos, redefinido para
     *        leer una Imagen de un archivo AIC.
     * \param[in] ruta String, es la ruta del archivo que se quiere leer.
     * \return Objeto del tipo Imagen.
     */
    Imagen leer(string ruta) override;

    /*!
     * \brief guardar Método heredado de la clase GestorDeArchivos, redefinido para
     *        guardar una Imagen de un archivo AIC.
     * \param[in] img Puntero a un objeto Imagen, que es la imagen a guardar.
     */
    void guardar(Imagen *img) override;

    /*!
     * \brief almacenarUltimaRuta Método heredado de la clase GestorDeArchivos, redefinido
     *        para almacenar una ruta de un archivo AIC.
     * \param[in] ruta String, es la ruta del último archivo leído que se quiere almacenar.
     */
    void almacenarUltimaRuta(string ruta) override;

private:
    /*!
     * \brief lineaAVector Método privado auxiliar para la lectura de un archivo AIC,
     *        que permite convertir un string en un vector de enteros.
     * \param linea String que se quiere convertir en vector de enteros.
     * \return vector de enteros con el contenido del string que se quería convertir.
     */
    vector<int> lineaAVector(string linea);
};

#endif // ARCHIVOAIC_H

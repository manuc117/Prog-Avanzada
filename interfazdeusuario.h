/*!
 *  \class      InterfazDeUsuario
 *  \brief      Clase capaz de ejecutar el sistema de procesamiento de imagenes digitales.
 *  \details    Tiene la capacidad de ejecutar todas las acciones que hacen funcionar el software.
 *              Posee un espacio de trabajo, un graficador y un puntero gestor de archivos.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef INTERFAZDEUSUARIO_H
#define INTERFAZDEUSUARIO_H

#include "espaciodetrabajo.h"
#include "ventanadegraficacion.h"
#include "gestordearchivos.h"
#include "imagen.h"
#include "archivopnm.h"
#include "archivoaic.h"
#include "ExcepcionArchivoNoSoportado.h"


class InterfazDeUsuario
{
public:
    InterfazDeUsuario();

    /*!
     * \brief ejecutar
     * \param[in] app
     * \param[out] app
     */
    void ejecutar(QApplication *app);

    int getOpcionCarpeta();

    int getOpcionArchivo(int opcion);

    /*!
     * \brief cargarImagen
     * \param[in] rutaArchi
     */
    void cargarImagen(string rutaArchi);

    void mostrarAtajos();

    string recuperarUltimaEjecucion();

private:
    /*!
     * \brief espTrabajo
     */
    EspacioDeTrabajo espTrabajo;

    VentanaDeGraficacion graficador;

    GestorDeArchivos *gestorArchi; //con puntero porque es abstracta

};

#endif // INTERFAZDEUSUARIO_H

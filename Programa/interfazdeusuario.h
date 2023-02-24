/*!
 *  \class      InterfazDeUsuario
 *  \brief      Clase capaz de ejecutar el sistema de procesamiento de imágenes digitales.
 *  \details    Tiene la capacidad de ejecutar todas las acciones que hacen funcionar el software.
 *              Posee un espacio de trabajo y una ventana de graficación.
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
#include "gestordearchivo.h"
#include "archivopnm.h"
#include "archivoaic.h"
#include "ExcepcionArchivoNoSoportado.h"


class InterfazDeUsuario
{
public:
    InterfazDeUsuario();

    /*!
     * \brief ejecutar Método que permite ejecutar el sistema.
     * \param[in] app QApplication que se ejecuta.
     * \param[out] app QApplication que muestra información como salida.
     */
    void ejecutar(QApplication *app);

    /*!
     * \brief getOpcionCarpeta Método que permite al usuario seleccionar la opción de
     *        la carpeta en la que se encuentra la Imagen que desea procesar.
     * \return Opción elegida por el usuario (puede ser una carpeta o no).
     */
    int getOpcionCarpeta();

    /*!
     * \brief getOpcionArchivo Método que permite al usuario seleccionar la opción del
     *        archivo que desea procesar.
     * \param[in] opcion Opcion de la carpeta elegida por el usuario.
     * \return Opción del archivo elegida por el usuario.
     */
    int getOpcionArchivo(int opcion);

    /*!
     * \brief mostrarAtajos Método que permite mostrar en pantalla los atajos de
     *        teclado y mouse que puede utilizar el usuario.
     */
    void mostrarAtajos();

    /*!
     * \brief recuperarUltimaEjecucion Método que permite recuperar la última Imagen Graficada.
     * \return Ruta de la última Imagen graficada.
     */
    string recuperarUltimaEjecucion();

private:
    /*!
     * \param espTrabajo Espacio de trabajo con el que trabaja el sistema.
     */
    EspacioDeTrabajo espTrabajo;

    /*!
     * \param graficador Ventana de graficación que utiliza el sistema para graficar
     *        una imagen.
     */
    VentanaDeGraficacion graficador;
};

#endif // INTERFAZDEUSUARIO_H

/*!
 *  \class      VentanaDeGraficacion
 *  \brief      Clase capaz de graficar una imagen, mostrarla en pantalla y responder a eventos.
 *  \details    Posee una imagen, que puede cargar. Conoce el ancho y alto de la ventana, y la
 *              escala utilizada para mantener sus proporciones. También es capaz
 *              de responder a eventos de teclado y mouse. Conoce la carpeta y el archivo
 *              seleccionados por el usuario.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 10-03-2023
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef VENTANADEGRAFICACION_H
#define VENTANADEGRAFICACION_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <iostream>
#include <QKeyEvent>

#include "imagen.h"
#include "espaciodetrabajo.h"
#include "gestordearchivo.h"
#include "archivoaic.h"
#include "archivopnm.h"
#include "procesadordeimagen.h"
#include "filtropasabajos.h"
#include "filtropasaaltos.h"
#include "filtromediana.h"
#include "negativo.h"
#include "contraste.h"
#include "brillo.h"
#include "binarizado.h"
#include "algoritmodelpintor.h"
#include "lut.h"
#include "graficadorhistograma.h"
#include "ExcepcionArchivoNoSoportado.h"

using namespace std;

class VentanaDeGraficacion: public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    /*!
     * \brief VentanaDeGraficacion Constructor del objeto VentanaDeGraficacion.
     */
    VentanaDeGraficacion();

    /*!
     * \brief setImagen Método que permite establecer la Imagen que se va a graficar.
     * \param[in] img Imagen que se desea graficar.
     */
    void setImagen(Imagen img);

    /*!
     * \brief asociarApp Método que permite asociar una QApplication.
     * \param[in] app Puntero a la QApplication que se asocia.
     */
    void asociarApp(QApplication* app);

    /*!
     * \brief initializeGL Método que inicializa los recursos necesarios para poder
     *        utilizar OpenGL.
     */
    void initializeGL() override;

    /*!
     * \brief paintGL Método que permite graficar.
     */
    void paintGL() override;

    /*!
     * \brief resizeGL Método que permite modificar el tamaño de la Imagen cuando se
     *        modifica el tamaño de la ventana.
     * \param[in] ancho Nuevo ancho de la ventana.
     * \param[in] alto  Nuevo alto de la ventana.
     */
    void resizeGL(int ancho, int alto) override;

    /*!
     * \brief graficarImagen Método que permite representar una Imagen de forma gráfica,
     *        utilizando la librería OpenGL.
     */
    void graficarImagen();

    /*!
     * \brief graficarImagenPseudocoloreada Método que permite representar una Imagen de forma gráfica,
     *        utilizando la librería OpenGL, pseudocoloreandola con una tabla de conversión o LUT.
     * \param[in] lut Tabla de conversión que se desea utilizar.
     */
    void graficarImagenPseudocoloreada(int lut);

    /*!
     * \brief setOpciones Método que permite establecer las opciones de carpeta y archivo seleccionadas
     *        por el usuario.
     * \param[in] opCarpeta Opción de carpeta elegida por el usuario.
     * \param[in] opArchi Opción de archivo elegida por el usuario.
     */
    void setOpciones(int opCarpeta, int opArchi);

    /*!
     * \brief cargarImagen Método que permite cargar una Imagen al graficador.
     * \param rutaArchi String, ruta del archivo de la Imagen que se quiere cargar.
     */
    void cargarImagen(string rutaArchi);

    /*!
     * \brief keyPressEvent Método heredado que permite recibir y responder a un evento de teclado.
     * \param[in] event Evento recibido.
     */
    void keyPressEvent(QKeyEvent *event) override;

    /*!
     * \brief mousePressEvent Método heredado que permite recibir y responder a un evento de mouse.
     * \param[in] event Evento recibido.
     */
    void mousePressEvent(QMouseEvent *event) override;

    /*!
     * \brief setEspTrabajo Método que permite establecer el espacio de trabajo con el que trabaja la ventana de graficación.
     * \param[in] newEspTrabajo Puntero al espacio de trabajo que se va a agregar.
     */
    void setEspTrabajo(EspacioDeTrabajo *newEspTrabajo);

private:
    /*!
     * \param imagen Imagen que se grafica.
     */
    Imagen imagen;

    /*!
     * \param opcionCarpeta Opción de carpeta seleccionada por el usuario.
     * \param opcionArchivo Opción de archivo seleccionada por el usuario.
     */
    int opcionCarpeta, opcionArchivo;

    /*!
     * \param anchoVentana Ancho de la ventana.
     * \param altoVentana Alto de la ventana.
     */
    int anchoVentana, altoVentana;

    /*!
     * \param seGraficaPseudocoloreada Bool que indica si la Imagen se grafica
     *        pseudocoloreada o no.
     */
    bool seGraficaPseudocoloreada = false;

    /*!
     * \param lut Tabla de conversión que se utiliza para pseudocolorear una Imagen.
     */
    int lut;

    /*!
     * \param escala Atributo que representa cuanto debe escalarse la Imagen para ser
     *        representada en la ventana, y para que ésta mantenga sus proporciones.
     */
    float escala;

    /*!
     * \param desplx Atributo que representa cuanto se desplaza en el eje 'x' la Imagen
     *        en la ventana.
     * \param desply Atributo que representa cuanto se desplaza en el eje 'y' la Imagen
     *        en la ventana.
     */
    float desplx, desply;

    /*!
     * \param aplicacion QApplication asociada.
     */
    QApplication* aplicacion;

    /*!
     * \param espTrabajo Espacio de trabajo con el que trabaja la VentanaDeGraficacion.
     */
    EspacioDeTrabajo* espTrabajo;
};

#endif // VENTANADEGRAFICACION_H

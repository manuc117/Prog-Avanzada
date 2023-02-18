/*!
 *  \class      VentanaDeGraficacion
 *  \brief      Clase capaz de graficar una imagen, mostrarla en pantalla y responder a eventos.
 *  \details    Posee una imagen, que puede cargar. Conoce el ancho y alto de la ventana, y la
 *              escala utilizada para mantener sus proporciones. También es capaz
 *              de responder a eventos de teclado y mouse. Conoce la carpeta y el archivo
 *              seleccionados por el usuario. Posee un puntero gestor de archivos.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
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
#include "gestordearchivos.h"
#include "archivoaic.h"
#include "archivopnm.h"
#include "filtros.h"
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

using namespace std;

class VentanaDeGraficacion: public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:

    VentanaDeGraficacion();
    void setImagen(Imagen img);
    void asociarApp(QApplication* app);

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int ancho, int alto) override;

    void graficarImagen();
    void graficarImagenPseudocoloreada(int lut);

    void setOpciones(int opCarpeta, int opArchi);
    void cargarImagen();

    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    Imagen imagen;

    int opcionCarpeta, opcionArchivo;

    GestorDeArchivos *gestorArchi;

    int anchoVentana, altoVentana;

    bool seGraficaPseudocoloreada = false;

    int lut;

    float escala;

    float desplx, desply;

    QApplication* aplicacion;
};

#endif // VENTANADEGRAFICACION_H

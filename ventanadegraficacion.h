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

using namespace std;

class VentanaDeGraficacion: public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:

    VentanaDeGraficacion();
    void cargarImagen(Imagen img);
    void asociarApp(QApplication* app);

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int ancho, int alto) override;

    void graficarImagen();

    void setOpciones(int opCarpeta, int opArchi);
    void cargarImagen();

    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    Imagen imagen;
    int opcionCarpeta, opcionArchivo;
    GestorDeArchivos *gestorArchi;

    // Atributos gráficos del dibujo en el graficador
    float escala;  // Para matenener las proporciones para cualquier ventana.
    float desplx, desply; // Para desplazar la imagen al centro de la ventana.
    QApplication* aplicacion;
};

#endif // VENTANADEGRAFICACION_H

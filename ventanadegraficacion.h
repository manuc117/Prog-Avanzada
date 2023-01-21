#ifndef VENTANADEGRAFICACION_H
#define VENTANADEGRAFICACION_H

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <iostream>
#include "imagen.h"

using namespace std;

class VentanaDeGraficacion: public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:

    VentanaDeGraficacion();
    void cargarImagen(Imagen &img);
    void asociarApp(QApplication* app);

    void initializeGL();
    void paintGL();
    void resizeGL(int ancho, int alto);

    void graficarImagen();
    void ejecutar();

private:
    Imagen *imagen;

    // Atributos gráficos del dibujo en el graficador
    float escala;  // Para matenener las proporciones para cualquier ventana.
    float desplx, desply; // Para desplazar la imagen al centro de la ventana.
    QApplication* aplicacion;
};

#endif // VENTANADEGRAFICACION_H

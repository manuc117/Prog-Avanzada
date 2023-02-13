#ifndef GRAFICADORHISTOGRAMA_H
#define GRAFICADORHISTOGRAMA_H

#include "procesadorestadistico.h"
#include "imagen.h"

#include <QApplication>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GraficadorHistograma: public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    GraficadorHistograma(Imagen &img);

    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int ancho, int alto) override;

    void graficarHistograma();

private:
    ProcesadorEstadistico procesador;

    Imagen imagen;

    int anchoVentana, altoVentana;

    vector<int> frecuenciaR;
    vector<int> frecuenciaG;
    vector<int> frecuenciaB;
    vector<int> frecuenciaProm;


    // Atributos gráficos del dibujo en el graficador
    float escala;  // Para matenener las proporciones para cualquier ventana.
    float desplx, desply; // Para desplazar la imagen al centro de la ventana.

};

#endif // GRAFICADORHISTOGRAMA_H

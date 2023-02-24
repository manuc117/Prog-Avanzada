/*!
 *  \class      GraficadorHistograma
 *  \brief      Clase capaz de mostrar en pantalla el histograma de una Imagen.
 *  \details    Se construye a partir de los distintos valores de R, G y B de una Imagen,
 *              y con esto es capaz de graficar su histograma.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
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
    /*!
     * \brief GraficadorHistograma Constructor del objeto GraficadorHistograma.
     * \param img Imagen de la cual se quiere graficar el histograma.
     */
    GraficadorHistograma(Imagen &img);

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
     * \brief resizeGL Método que permite modificar el tamaño del gráfico cuando se
     *        modifica el tamaño de la ventana.
     * \param[in] ancho Nuevo ancho de la ventana.
     * \param[in] alto  Nuevo alto de la ventana.
     */
    void resizeGL(int ancho, int alto) override;

    /*!
     * \brief graficarHistograma Método que grafica el histograma de una Imagen
     *        utilizando la librería OpenGL.
     */
    void graficarHistograma();

private:
    /*!
     * \param procesador Objeto ProcesadorEstadístico asociado al GraficadorHistograma,
     *        que colabora en obtener las frecuencias de los distintos valores de R, G y B.
     */
    ProcesadorEstadistico procesador;

    /*!
     * \param anchoVentana Ancho de la ventana.
     * \param altoVentana  Alto de la ventana.
     */
    int anchoVentana, altoVentana;

    /*!
     * \param frecuenciaR Vector de enteros que representa las frecuencias para los
     *        distintos niveles de rojo. Cada posición equivale a un nivel de rojo y
     *        el entero almacenado en ella es su frecuencia.
     */
    vector<int> frecuenciaR;

    /*!
     * \param frecuenciaG Vector de enteros que representa las frecuencias para los
     *        distintos niveles de verde. Cada posición equivale a un nivel de verde y
     *        el entero almacenado en ella es su frecuencia.
     */
    vector<int> frecuenciaG;

    /*!
     * \param frecuenciaB Vector de enteros que representa las frecuencias para los
     *        distintos niveles de azul. Cada posición equivale a un nivel de azul y
     *        el entero almacenado en ella es su frecuencia.
     */
    vector<int> frecuenciaB;

    /*!
     * \param frecuenciaProm Vector de enteros que representa la frecuencia con la que
     *        aparece cada promedio de RGB ((R+G+B)/3).
     */
    vector<int> frecuenciaProm;

    /*!
     * \param escala Atributo que representa cuanto debe escalarse el gráfico para ser
     *        representado en la ventana, y para que esta mantenga sus proporciones.
     */
    float escala;

    /*!
     * \param desplx Atributo que representa cuanto se desplaza en el eje 'x' el histograma
     *        en la ventana.
     * \param desply Atributo que representa cuanto se desplaza en el eje 'y' el histograma
     *        en la ventana.
     */
    float desplx, desply;

};

#endif // GRAFICADORHISTOGRAMA_H

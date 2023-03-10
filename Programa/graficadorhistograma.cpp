#include "graficadorhistograma.h"

GraficadorHistograma::GraficadorHistograma(Imagen &img)
{
    frecuenciaR = procesador.getFrecuenciaR(img);
    frecuenciaG = procesador.getFrecuenciaG(img);
    frecuenciaB = procesador.getFrecuenciaB(img);
    frecuenciaProm = procesador.getFrecuenciaPromedio(img);
}

void GraficadorHistograma::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void GraficadorHistograma::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    graficarHistograma();
}

void GraficadorHistograma::resizeGL(int ancho, int alto)
{
    anchoVentana = ancho;
    altoVentana = alto;

    glViewport(0, 0, anchoVentana, altoVentana);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width(), 0, height(), -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GraficadorHistograma::graficarHistograma()
{
    glPushMatrix();
    glTranslatef(desplx, desply, 0.0f);

    vector<int> maximos =
    {
        *max_element(frecuenciaR.begin(), frecuenciaR.end()),
        *max_element(frecuenciaG.begin(), frecuenciaG.end()),
        *max_element(frecuenciaB.begin(), frecuenciaB.end()),
        *max_element(frecuenciaProm.begin(), frecuenciaProm.end())
    };

    float maxFrecuencia = *max_element(maximos.begin(), maximos.end());

    glScalef(float(width())/float(frecuenciaR.size()), float(height())/float(maxFrecuencia), 1.0f);

    glBegin(GL_LINE_STRIP);
        for(int nivel=0; nivel<frecuenciaR.size(); nivel++)
        {
            glColor3f(255, 0, 0);
            glVertex3i(nivel, frecuenciaR[nivel], 1);
        }
    glEnd();

    glBegin(GL_LINE_STRIP);
        for(int nivel=0; nivel<frecuenciaG.size(); nivel++)
        {
            glColor3f(0, 255, 0);
            glVertex3i(nivel, frecuenciaG[nivel], 0);
        }
    glEnd();

    glBegin(GL_LINE_STRIP);
        for(int nivel=0; nivel<frecuenciaB.size(); nivel++)
        {
            glColor3f(0, 0, 255);
            glVertex3i(nivel, frecuenciaB[nivel], -1);
        }
    glEnd();

    glBegin(GL_LINE_STRIP);
        for(int nivel=0; nivel<frecuenciaProm.size(); nivel++)
        {
            glColor3f(0,0,0);
            glVertex3i(nivel, frecuenciaProm[nivel], 0);
        }
    glEnd();

    glPopMatrix();
}

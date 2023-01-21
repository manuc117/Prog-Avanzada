#include "ventanadegraficacion.h"

VentanaDeGraficacion::VentanaDeGraficacion()
{

}

void VentanaDeGraficacion::cargarImagen(Imagen &img)
{
    imagen = &img;
}

void VentanaDeGraficacion::asociarApp(QApplication *app)
{
    aplicacion = app;
}

void VentanaDeGraficacion::initializeGL()
{
    initializeOpenGLFunctions();

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void VentanaDeGraficacion::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float relAncho = ((float)width())  / ((float)imagen->getColumnas());
    float relAlto  = ((float)height()) / ((float)imagen->getFilas());

    escala = 1.0f;
    desplx = 0.0f;
    desply = 0.0f;

    if(relAncho < relAlto)
    {
        escala = relAncho;
        desply = (height() - imagen->getFilas()*escala)*0.5f;
    }
    else
    {
        escala = relAlto;
        desplx = (width() - imagen->getColumnas()*escala)*0.5f;
    }

    graficarImagen();
}

void VentanaDeGraficacion::resizeGL(int ancho, int alto)
{
    glViewport(0, 0, ancho, alto);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(0, width(), 0, height(), -1, 1);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
}

void VentanaDeGraficacion::graficarImagen()
{
    Pixel pixAux;

    glPushMatrix();

    glTranslatef(desplx, desply, 0.0f);

    glScalef(escala, escala, 1.0f);

    glBegin(GL_QUADS);


        for (int fila=0; fila<imagen->getFilas(); fila++)
        {
            for (int columna=0; columna<imagen->getColumnas(); columna++)
            {
                pixAux = imagen->getPixel(fila,columna);

                glColor3f((float)pixAux.getRed()/imagen->getRango(), (float)pixAux.getGreen()/imagen->getRango(), (float)pixAux.getBlue()/imagen->getRango());

                glVertex3i(columna, imagen->getFilas()-fila, 0);
                glVertex3i(columna, imagen->getFilas()-(fila+1), 0);
                glVertex3i(columna+1, imagen->getFilas()-(fila+1), 0);
                glVertex3i(columna+1, imagen->getFilas()-fila, 0);

            }
        }

    glEnd();

    glPopMatrix();

}

void VentanaDeGraficacion::ejecutar()
{
   aplicacion->exec();
}

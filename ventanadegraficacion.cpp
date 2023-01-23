#include "ventanadegraficacion.h"

VentanaDeGraficacion::VentanaDeGraficacion()
{

}

void VentanaDeGraficacion::cargarImagen(Imagen img)
{
    imagen = img;
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

    float relAncho = ((float)width())  / ((float)imagen.getColumnas());
    float relAlto  = ((float)height()) / ((float)imagen.getFilas());

    escala = 1.0f;
    desplx = 0.0f;
    desply = 0.0f;

    if(relAncho < relAlto)
    {
        escala = relAncho;
        desply = (height() - imagen.getFilas()*escala)*0.5f;
    }
    else
    {
        escala = relAlto;
        desplx = (width() - imagen.getColumnas()*escala)*0.5f;
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

    for (int fila=0; fila<imagen.getFilas(); fila++)
    {
        for (int columna=0; columna<imagen.getColumnas(); columna++)
        {
            pixAux = imagen.getPixel(fila,columna);

            glColor3f((float)pixAux.getRed()/imagen.getRango(), (float)pixAux.getGreen()/imagen.getRango(), (float)pixAux.getBlue()/imagen.getRango());

            glVertex3i(columna, imagen.getFilas()-fila, 0);
            glVertex3i(columna, imagen.getFilas()-(fila+1), 0);
            glVertex3i(columna+1, imagen.getFilas()-(fila+1), 0);
            glVertex3i(columna+1, imagen.getFilas()-fila, 0);

        }
    }

    glEnd();

    glPopMatrix();

}

void VentanaDeGraficacion::setOpciones(int opCarpeta, int opArchi)
{
    opcionCarpeta = opCarpeta;
    opcionArchivo = opArchi;
}

void VentanaDeGraficacion::cargarImagen()
{
    EspacioDeTrabajo espTrabajo;
    string rutaArchi = espTrabajo.getRutaArchivo(opcionCarpeta, opcionArchivo);

    if (espTrabajo.esPNM(rutaArchi))
    {
        gestorArchi = new ArchivoPNM;
        cargarImagen(gestorArchi ->leer(rutaArchi));
    }
    else if(espTrabajo.esAIC(rutaArchi))
    {
        gestorArchi = new ArchivoAIC;
        cargarImagen(gestorArchi->leer(rutaArchi));
    }
}

void VentanaDeGraficacion::keyPressEvent(QKeyEvent *event)
{
    bool ctrl= event->modifiers() == Qt::ControlModifier;
    bool izquierda= event->key() == Qt::Key_Left;
    bool derecha= event->key() == Qt::Key_Right;
    bool guardar= event->key() == Qt::Key_G;
    bool suavizado= event->key() == Qt::Key_S;

    if (izquierda and ctrl)
    {
        if (opcionArchivo == 0)
        {
            EspacioDeTrabajo espTrabajo;
            opcionArchivo = espTrabajo.getNombreArchivos(opcionCarpeta).size()-1;
        }
        else
        {
             --opcionArchivo;
        }

        cout<<"Ctrl + flecha izquierda: mostrar imagen anterior.\n";
        cout.flush();

        cargarImagen();
        repaint();
    }

    if (derecha and ctrl)
    {
        EspacioDeTrabajo espTrabajo;
        if (opcionArchivo == espTrabajo.getNombreArchivos(opcionCarpeta).size()-1)
        {
            opcionArchivo = 0;
        }
        else
        {
            ++opcionArchivo;
        }

        cout<<"Ctrl + flecha derecha: mostrar imagen siguiente.\n";
        cout.flush();

        cargarImagen();
        repaint();
    }

    if (guardar and ctrl)
    {
        EspacioDeTrabajo espTrabajo;
        cout<<"Ctrl + g: guardar imagen.";
        cout.flush();
        string ruta = espTrabajo.getRutaArchivo(opcionCarpeta, opcionArchivo);
        aplicacion->closeAllWindows();
        espTrabajo.guardarImagen(&imagen);
    }

    if (suavizado and ctrl)
    {
        Filtros *filtro;
        filtro = new FiltroPasaBajos;

        cout<<"Ctrl + s: aplicar suavizado.";
        cout.flush();

        imagen = filtro->aplicarFiltro(imagen);
        repaint();
    }

}


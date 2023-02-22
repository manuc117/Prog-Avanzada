#include "ventanadegraficacion.h"

VentanaDeGraficacion::VentanaDeGraficacion()
{

}

void VentanaDeGraficacion::setImagen(Imagen img)
{
    seGraficaPseudocoloreada = false;
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

    if(!seGraficaPseudocoloreada)
        graficarImagen();
    else if(seGraficaPseudocoloreada)
        graficarImagenPseudocoloreada(lut);
}

void VentanaDeGraficacion::resizeGL(int ancho, int alto)
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

void VentanaDeGraficacion::graficarImagenPseudocoloreada(int lut)
{
    LUT tablaLUT(lut);
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
            pixAux = tablaLUT.pseudocolorear(pixAux.getIntensidad());

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
    string rutaArchi = espTrabajo.getRutaArchivo(opcionCarpeta, opcionArchivo);

    if (espTrabajo.esPNM(rutaArchi))
    {
            gestorArchi = new ArchivoPNM;
            setImagen(gestorArchi ->leer(rutaArchi));
    }
    else if(espTrabajo.esAIC(rutaArchi))
    {
            gestorArchi = new ArchivoAIC;
            setImagen(gestorArchi->leer(rutaArchi));
    }
}

void VentanaDeGraficacion::keyPressEvent(QKeyEvent *event)
{
    bool ctrl= event->modifiers() == Qt::ControlModifier;
    bool izquierda= event->key() == Qt::Key_Left;
    bool derecha= event->key() == Qt::Key_Right;
    bool guardar= event->key() == Qt::Key_G;
    bool suavizado= event->key() == Qt::Key_S;
    bool altos= event->key() == Qt::Key_A;
    bool mediana= event->key() == Qt::Key_M;
    bool mas= event->key() == Qt::Key_Plus;
    bool menos= event->key() == Qt::Key_Comma;
    /*El atajo ctrl + la tecla menos no funcionan en mi dispositivo,
    por lo que tuve que cambiar el menos por otra tecla.*/

    bool negativo= event->key() == Qt::Key_N;
    bool contraste= event->key() == Qt::Key_C;
    bool binarizar= event->key() == Qt::Key_B;
    bool uno= event->key() == Qt::Key_1;
    bool dos= event->key() == Qt::Key_2;
    bool histograma= event->key() == Qt::Key_H;

    if (izquierda and ctrl)
    {
        if (opcionArchivo == 0)
        {
            opcionArchivo = espTrabajo.getNombreArchivos(espTrabajo.getRutaCarpeta(opcionCarpeta)).size()-1;
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
        if (opcionArchivo == espTrabajo.getNombreArchivos(espTrabajo.getRutaCarpeta(opcionCarpeta)).size()-1)
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
        cout<<"Ctrl + G: guardar imagen.\n";
        cout.flush();
        string ruta = espTrabajo.getRutaArchivo(opcionCarpeta, opcionArchivo);
        aplicacion->closeAllWindows();
        espTrabajo.guardarImagen(&imagen);
    }

    if (suavizado and ctrl)
    {
        Filtros *filtro;
        filtro = new FiltroPasaBajos;

        cout<<"Ctrl + S: aplicar filtro pasa bajos (suavizado).\n";
        cout.flush();

        imagen = filtro->aplicarFiltro(imagen);
        repaint();
    }

    if (altos and ctrl)
    {
        Filtros *filtro;
        filtro = new FiltroPasaAltos;

        cout<<"Ctrl + A: aplicar filtro pasa altos (realce de bordes).\n";
        cout.flush();

        imagen = filtro->aplicarFiltro(imagen);
        repaint();
    }

    if (mediana and ctrl)
    {
        Filtros *filtro;
        filtro = new FiltroMediana;

        cout<<"Ctrl + M: aplicar filtro de mediana.\n";
        cout.flush();

        imagen = filtro->aplicarFiltro(imagen);
        repaint();
    }

    if (mas and ctrl)
    {
        Filtros *filtro;
        filtro = new Brillo(1);

        cout<<"Ctrl + '+': aumentar brillo.\n";
        cout.flush();

        aplicacion->closeAllWindows();
        imagen = filtro->aplicarFiltro(imagen);
        show();
        repaint();
    }

    if (menos and ctrl)
    {
        Filtros *filtro;
        filtro = new Brillo(2);

        cout<<"Ctrl + coma ',': reducir brillo.\n";
        cout.flush();

        aplicacion->closeAllWindows();
        imagen = filtro->aplicarFiltro(imagen);
        show();
        repaint();
    }

    if (negativo and ctrl)
    {
        Filtros *filtro;
        filtro = new Negativo;

        cout<<"Ctrl + N: aplicar negativo.\n";
        cout.flush();

        imagen = filtro->aplicarFiltro(imagen);
        repaint();
    }

    if(contraste and ctrl)
    {
        Filtros *filtro;
        filtro = new Contraste;

        cout<<"Ctrl + C: ajustar contraste.\n";
        cout.flush();

        imagen = filtro->aplicarFiltro(imagen);
        repaint();
    }

    if(binarizar and ctrl)
    {
        Filtros *filtro;
        filtro = new Binarizado;

        cout<<"Ctrl + C: binarizar imagen.\n";
        cout.flush();

        aplicacion->closeAllWindows();
        imagen = filtro->aplicarFiltro(imagen);
        show();
        repaint();
    }

    if(uno and ctrl)
    {
        cout<<"Ctrl + 1: pseudocolorear la imagen con glow.lut.\n";
        cout.flush();

        seGraficaPseudocoloreada = true;
        lut = 1;
        show();
        repaint();
    }

    if(dos and ctrl)
    {
        cout<<"Ctrl + 2: pseudocolorear la imagen con Turbo.lut.\n";
        cout.flush();

        seGraficaPseudocoloreada = true;
        lut = 2;
        show();
        repaint();
    }

    if(histograma and ctrl)
    {
        ProcesadorEstadistico proce;
        GraficadorHistograma* graficador;
        graficador = new GraficadorHistograma(imagen);

        cout<<"Ctrl + H: graficar histograma e informar datos estadisticos.\n";
        cout.flush();

        proce.informarDatosEstadisticos(imagen);
        graficador->graficarHistograma();
        graficador->show();
    }

}

void VentanaDeGraficacion::mousePressEvent(QMouseEvent *event)
{
    bool clickIzq = event->button() == Qt::LeftButton;
    bool ctrl = event->modifiers() == Qt::ControlModifier;

    if(clickIzq and ctrl)
    {
        AlgoritmoDelPintor Pintor(imagen);

        cout<<"\nCtrl + click izquierdo: aplicar algortimo del pintor.\n";
        cout.flush();

        int f = altoVentana - (QCursor::pos().y() - this->pos().y());
        int c = QCursor::pos().x() - this->pos().x();

        f -= desply;
        f = f/escala;
        c -= desplx;
        c = c/escala;

        f = imagen.getFilas()-1-f;

        aplicacion->closeAllWindows();
        imagen = Pintor.aplicarAlgoritmo(f, c);
        show();
        repaint();

    }
}



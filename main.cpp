#include <QApplication>
#include "ventanadegraficacion.h"
#include "archivopnm.h"
#include "imagen.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VentanaDeGraficacion graficador;

    graficador.asociarApp(&a);

    ArchivoPNM archivos;

    Imagen img = archivos.leer("test_02.ppm");

    graficador.cargarImagen(img);

    graficador.show();

    a.exec();

    return 0;
}

#include <QApplication>
#include "sistema.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString titulo = QString::fromStdString("Software de Procesamiento Digital de Imágenes");

    a.setApplicationName(titulo);

    Sistema sistema;

    sistema.ejecutar(&a);

    return 0;
}

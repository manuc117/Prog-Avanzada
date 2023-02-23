#include <QApplication>
#include "interfazdeusuario.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InterfazDeUsuario interfaz;

    interfaz.ejecutar(&a);

    return 0;
}

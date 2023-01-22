#include <QApplication>
#include "ventanadegraficacion.h"
#include "archivopnm.h"
#include "imagen.h"
#include "espaciodetrabajo.h"
#include "interfazdeusuario.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    VentanaDeGraficacion graficador;

//    graficador.asociarApp(&a);

//    ArchivoPNM archivos;

//    Imagen img = archivos.leer("test_02.ppm");

//    graficador.cargarImagen(img);

//    graficador.show();

//    a.exec();

//    EspacioDeTrabajo espacio;
//    vector<string> carpetas = espacio.getCarpetas();
//    for(int carpeta=0; carpeta<carpetas.size(); carpeta++)
//        cout<<carpetas[carpeta]<<endl;
//    int opcion;
//    cout<<"Seleccionar carpeta: ";
//    cin>>opcion;

//    vector<string> lista = espacio.getNombreArchivos(opcion-1);

//    for(int carpeta=0; carpeta<lista.size(); carpeta++)
//        cout<<lista[carpeta]<<endl;

    InterfazDeUsuario interfaz;

    interfaz.ejecutar(&a);

    return 0;
}

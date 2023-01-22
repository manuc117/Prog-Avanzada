#include "interfazdeusuario.h"

InterfazDeUsuario::InterfazDeUsuario()
{

}

void InterfazDeUsuario::ejecutar(QApplication *app)
{
    int opcionCarpeta = getOpcionCarpeta();

    system("cls");

    int opcionArchivo = getOpcionArchivo(opcionCarpeta);

    string rutaArchi = espTrabajo.getRutaArchivo(opcionCarpeta-1, opcionArchivo-1);

    cargarImagen(rutaArchi, opcionCarpeta-1, opcionArchivo-1);

    graficador.asociarApp(app);

    graficador.show();

    app->exec();
}

int InterfazDeUsuario::getOpcionCarpeta()
{
    vector<string> carpetas = espTrabajo.getCarpetas();
    for(int carpeta=0; carpeta<carpetas.size(); carpeta++)
        cout<<carpeta+1<<"- "<<carpetas[carpeta]<<endl;

    int opcion;
    cout<<endl<<"Seleccione una carpeta: ";
    cin>>opcion;

    while(opcion<1 or opcion>carpetas.size() or !cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Seleccione una opcion valida: ";
        cin>>opcion;
    }

    return opcion;
}

int InterfazDeUsuario::getOpcionArchivo(int opcionCarpeta)
{
    vector<string> carpetas = espTrabajo.getCarpetas();
    cout<<carpetas[opcionCarpeta-1]<<": "<<endl;

    vector<string> listaDeArchivos = espTrabajo.getNombreArchivos(opcionCarpeta-1);
    for(int archivo=0; archivo<listaDeArchivos.size(); archivo++)
        cout<<"\t"<<archivo+1<<"- "<<listaDeArchivos[archivo]<<endl;

    int opcion;
    cout<<endl<<"\tSeleccione un archivo: ";
    cin>>opcion;

    while(opcion<1 or opcion>listaDeArchivos.size() or !cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"\tSeleccione una opcion valida: ";
        cin>>opcion;
    }

    return opcion;
}

void InterfazDeUsuario::cargarImagen(string rutaArchi, int opcionCarpeta, int opcionArchivo)
{
    graficador.setOpciones(opcionCarpeta, opcionArchivo);

    if (espTrabajo.esPNM(rutaArchi))
    {
        gestorArchi = new ArchivoPNM;
        graficador.cargarImagen(gestorArchi ->leer(rutaArchi));
    }
    else if(espTrabajo.esAIC(rutaArchi))
    {
        gestorArchi = new ArchivoAIC;
        graficador.cargarImagen(gestorArchi->leer(rutaArchi));
    }
}





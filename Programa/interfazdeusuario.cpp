#include "interfazdeusuario.h"

InterfazDeUsuario::InterfazDeUsuario()
{

}

void InterfazDeUsuario::ejecutar(QApplication *app)
{
    bool seEstaEjecutando = true;
    bool seGraficoImagen = false;

    while(seEstaEjecutando)
    {

        int opcionCarpeta = getOpcionCarpeta();

        if (opcionCarpeta != espTrabajo.getCarpetas().size()+1 and opcionCarpeta != espTrabajo.getCarpetas().size()+2)
        {
            system("cls");

            int opcionArchivo = getOpcionArchivo(opcionCarpeta);

            if(opcionArchivo != -1)
            {
                string rutaArchi = espTrabajo.getRutaArchivo(opcionCarpeta-1, opcionArchivo-1);

                mostrarAtajos();

                try
                {
                    graficador.setOpciones(opcionCarpeta-1, opcionArchivo-1);

                    graficador.cargarImagen(rutaArchi);

                    graficador.asociarApp(app);

                    graficador.show();

                    app->exec();

                    system("cls");

                    seGraficoImagen = true;
                }
                catch(ExcepcionArchivoCorrupto &excepcion)
                {
                    system("cls");
                    app->closeAllWindows();
                    cout<<excepcion.what()<<endl;

                    seGraficoImagen = false;
                }
                catch(ExcepcionArchivoNoSoportado &excepcion)
                {
                    system("cls");
                    app->closeAllWindows();
                    cout<<excepcion.what()<<endl;

                    seGraficoImagen = false;
                }
            }
        }
        else if(opcionCarpeta == espTrabajo.getCarpetas().size()+1)
        {
            if(seGraficoImagen)
            {
                system("cls");

                mostrarAtajos();

                graficador.cargarImagen(recuperarUltimaEjecucion());

                graficador.asociarApp(app);

                graficador.show();

                app->exec();

                system("cls");

                seGraficoImagen = true;
            }
            else if(!seGraficoImagen)
            {
                system("cls");
                cout<<"No se pudo recuperar la ultima ejecucion dado que anteriormente no se grafico una imagen.\nPor favor seleccione otra opcion.\n\n";
                cout.flush();
            }
        }
        else
        {
            break;
        }
    }

}

int InterfazDeUsuario::getOpcionCarpeta()
{
    vector<string> carpetas = espTrabajo.getCarpetas();
    for(int carpeta=0; carpeta<carpetas.size(); carpeta++)
        cout<<carpeta+1<<"- "<<carpetas[carpeta]<<endl;

    cout<<carpetas.size()+1<<"- Recuperar la ultima ejecucion\n";
    cout<<carpetas.size()+2<<"- Cerrar programa\n";

    int opcion;
    cout<<endl<<"Seleccione una opcion: ";
    cin>>opcion;

    while(opcion<1 or opcion>carpetas.size()+2 or !cin.good())
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

    vector<string> listaDeArchivos = espTrabajo.getNombreArchivos(espTrabajo.getRutaCarpeta(opcionCarpeta-1));
    for(int archivo=0; archivo<listaDeArchivos.size(); archivo++)
        cout<<"\t"<<archivo+1<<"- "<<listaDeArchivos[archivo]<<endl;

    cout<<"\t"<<listaDeArchivos.size()+1<<"- Volver a la seleccion de carpetas\n";

    int opcion;
    cout<<endl<<"\tSeleccione una opcion: ";
    cin>>opcion;

    while(opcion<1 or opcion>listaDeArchivos.size()+1 or !cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"\tSeleccione una opcion valida: ";
        cin>>opcion;
    }

    if (opcion == listaDeArchivos.size()+1)
    {
        system("cls");
        return -1;
    }

    return opcion;
}

void InterfazDeUsuario::mostrarAtajos()
{
    cout<<"\n\t----Lista de atajos----\n";
    cout<<"\t- Mostrar imagen anterior: Ctrl + flecha izquierda\n";
    cout<<"\t- Mostrar imagen siguiente: Ctrl + flecha derecha\n";
    cout<<"\t- Guardar imagen: Ctrl + G\n";
    cout<<"\t- Mostrar histograma: Ctrl + H\n";
    cout<<"\t- Ajustar contraste: Ctrl + C\n";
    cout<<"\t- Aumentar brillo: Ctrl + '+'\n";
    cout<<"\t- Reducir  brillo: Ctrl + ','\n";
    cout<<"\t- Detectar area con el color o intensidad del pixel debajo del cursor: Ctrl + click izquierdo\n";
    cout<<"\t- Aplicar pseudocoloreado: Ctrl + nro de LUT.\n\t\t1) glow.lut\n\t\t2) Turbo.lut\n";
    cout<<"\t- Aplicar filtro pasa bajos (suavizado): Ctrl + S\n";
    cout<<"\t- Aplicar filtro pasa altos: Ctrl + A\n";
    cout<<"\t- Aplicar filtro de mediana: Ctrl + M\n";
    cout<<"\t- Aplicar negativo: Ctrl + N\n";
    cout<<"\t- Binarizar imagen: Ctrl + B\n\n";
}

string InterfazDeUsuario::recuperarUltimaEjecucion()
{
    string ultimaRuta;
    ifstream archi;

    archi.open("registro.txt");
    archi>>ultimaRuta;

    archi.close();

    return ultimaRuta;
}


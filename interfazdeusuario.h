#ifndef INTERFAZDEUSUARIO_H
#define INTERFAZDEUSUARIO_H

#include "espaciodetrabajo.h"
#include "ventanadegraficacion.h"
#include "gestordearchivos.h"
#include "imagen.h"
#include "archivopnm.h"
#include "archivoaic.h"
#include "ExcepcionArchivoNoSoportado.h"

class InterfazDeUsuario
{
public:
    InterfazDeUsuario();

    void ejecutar(QApplication *app);

    int getOpcionCarpeta();

    int getOpcionArchivo(int opcion);

    void cargarImagen(string rutaArchi, int opcionCarpeta, int opcionArchivo);

    void mostrarAtajos();

private:

    EspacioDeTrabajo espTrabajo;

    VentanaDeGraficacion graficador;

    GestorDeArchivos *gestorArchi; //con puntero porque es abstracta

};

#endif // INTERFAZDEUSUARIO_H

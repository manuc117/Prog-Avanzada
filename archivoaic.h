#ifndef ARCHIVOAIC_H
#define ARCHIVOAIC_H

#include "gestordearchivos.h"
#include "ExcepcionArchivoCorrupto.h"

#include <fstream>
#include <iostream>

using namespace std;

class ArchivoAIC: public GestorDeArchivos
{
public:
    ArchivoAIC();

    Imagen leer(string ruta) override;

    void guardar(Imagen *img) override;

    void almacenarUltimaRuta(string ruta) override;

    vector<int> lineaAVector(string linea);

};

#endif // ARCHIVOAIC_H

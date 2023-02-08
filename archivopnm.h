#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H

#include "gestordearchivos.h"
#include "ExcepcionArchivoCorrupto.h"

#include <fstream>
#include <iostream>

using namespace std;

class ArchivoPNM: public GestorDeArchivos
{
public:
    ArchivoPNM();

    Imagen leer(string ruta) override;

    void guardar(Imagen *img) override;

private:

    string getExtension(string identificador);

};

#endif // ARCHIVOPNM_H

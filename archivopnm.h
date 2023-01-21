#ifndef ARCHIVOPNM_H
#define ARCHIVOPNM_H

#include "gestordearchivos.h"
#include <fstream>
#include <iostream>

using namespace std;

class ArchivoPNM: public GestorDeArchivos
{
public:
    ArchivoPNM();

    Imagen leer(string ruta) override;



private:


};

#endif // ARCHIVOPNM_H

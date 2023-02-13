#ifndef EXCEPCIONARCHIVOCORRUPTO_H
#define EXCEPCIONARCHIVOCORRUPTO_H

#include <stdexcept>

using namespace std;

class ExcepcionArchivoCorrupto: public runtime_error
{
public:

    ExcepcionArchivoCorrupto():
        runtime_error("El archivo esta corrupto, no se puede leer la imagen. Por favor seleccione otra opcion.\n"){}
};

#endif // EXCEPCIONARCHIVOCORRUPTO_H

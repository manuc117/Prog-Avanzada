#ifndef LUT_H
#define LUT_H

#include "imagen.h"

#include <string>
#include <vector>
#include <fstream>


class LUT
{
public:
    LUT(int opcion);

    Pixel pseudocolorear(int intensidad);

    void cargarTabla(int opcion);

private:

    vector<string> grupoLuts
    {
        "./grupo_luts/glow.lut",
        "./grupo_luts/Turbo.lut"
    };

    vector<vector<int>> tabla;
};

#endif // LUT_H

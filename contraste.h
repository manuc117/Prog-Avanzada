/*!
 *  \class      Contraste
 *  \brief      Clase que hereda el método de la clase Filtros y lo redefine para aplicar el
 *              ajuste de contraste sobre una imagen.
 *  \details    Permite ajustar el contraste de una imagen.
 *  \author     Manuela Calvo
 *  \date       Fecha de última modificación: 15-02-2022
 *  \pre
 *  \bug
 *  \warning
*/
#ifndef CONTRASTE_H
#define CONTRASTE_H

#include "filtros.h"
#include "procesadorestadistico.h"

class Contraste: public Filtros
{
public:
    /*!
     * \brief Contraste Constructor del objeto contraste.
     */
    Contraste();

    /*!
     * \brief aplicarFiltro Método heredado de la clase Filtros, redefinido
     *        para aplicar el ajuste de contraste a una imagen.
     * \param img Imagen sobre la que se aplica el ajuste de contraste.
     * \return Imagen con el ajuste de contraste aplicado.
     */
    Imagen aplicarFiltro(Imagen &img) override;
};

#endif // CONTRASTE_H

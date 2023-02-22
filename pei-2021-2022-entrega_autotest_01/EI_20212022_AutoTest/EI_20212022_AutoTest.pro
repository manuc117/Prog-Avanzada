QT += testlib
QT -= gui
QT += widgets

LIBS += -lopengl32

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_ei_autotest.cpp \
    ../../algoritmodelpintor.cpp \
    ../../archivoaic.cpp \
    ../../archivopnm.cpp \
    ../../binarizado.cpp \
    ../../brillo.cpp \
    ../../contraste.cpp \
    ../../espaciodetrabajo.cpp \
    ../../filtromediana.cpp \
    ../../filtropasaaltos.cpp \
    ../../filtropasabajos.cpp \
    ../../filtros.cpp \
    ../../gestordearchivos.cpp \
    ../../graficadorhistograma.cpp \
    ../../imagen.cpp \
    ../../interfazdeusuario.cpp \
    ../../lut.cpp \
    ../../negativo.cpp \
    ../../pixel.cpp \
    ../../procesadorestadistico.cpp \
    ../../ventanadegraficacion.cpp
HEADERS += \
    ../../ExcepcionArchivoCorrupto.h \
    ../../ExcepcionArchivoNoSoportado.h \
    ../../algoritmodelpintor.h \
    ../../archivoaic.h \
    ../../archivopnm.h \
    ../../binarizado.h \
    ../../brillo.h \
    ../../contraste.h \
    ../../espaciodetrabajo.h \
    ../../filtromediana.h \
    ../../filtropasaaltos.h \
    ../../filtropasabajos.h \
    ../../filtros.h \
    ../../gestordearchivos.h \
    ../../graficadorhistograma.h \
    ../../imagen.h \
    ../../interfazdeusuario.h \
    ../../lut.h \
    ../../negativo.h \
    ../../pixel.h \
    ../../procesadorestadistico.h \
    ../../ventanadegraficacion.h

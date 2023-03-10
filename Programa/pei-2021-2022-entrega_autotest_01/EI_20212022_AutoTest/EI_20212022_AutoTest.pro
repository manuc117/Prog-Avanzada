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
    ../../gestordearchivo.cpp \
    ../../graficadorhistograma.cpp \
    ../../imagen.cpp \
    ../../lut.cpp \
    ../../negativo.cpp \
    ../../pixel.cpp \
    ../../procesadordeimagen.cpp \
    ../../procesadorestadistico.cpp \
    ../../sistema.cpp \
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
    ../../gestordearchivo.h \
    ../../graficadorhistograma.h \
    ../../imagen.h \
    ../../lut.h \
    ../../negativo.h \
    ../../pixel.h \
    ../../procesadordeimagen.h \
    ../../procesadorestadistico.h \
    ../../sistema.h \
    ../../ventanadegraficacion.h

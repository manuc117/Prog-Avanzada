QT -= gui

QT += widgets
LIBS += -lopengl32

CONFIG += c++11 console qt
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        algoritmodelpintor.cpp \
        archivoaic.cpp \
        archivopnm.cpp \
        binarizado.cpp \
        brillo.cpp \
        contraste.cpp \
        espaciodetrabajo.cpp \
        filtromediana.cpp \
        filtropasaaltos.cpp \
        filtropasabajos.cpp \
        gestordearchivo.cpp \
        graficadorhistograma.cpp \
        imagen.cpp \
        lut.cpp \
        main.cpp \
        negativo.cpp \
        pixel.cpp \
        procesadordeimagen.cpp \
        procesadorestadistico.cpp \
        sistema.cpp \
        ventanadegraficacion.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ExcepcionArchivoCorrupto.h \
    ExcepcionArchivoNoSoportado.h \
    algoritmodelpintor.h \
    archivoaic.h \
    archivopnm.h \
    binarizado.h \
    brillo.h \
    contraste.h \
    espaciodetrabajo.h \
    filtromediana.h \
    filtropasaaltos.h \
    filtropasabajos.h \
    gestordearchivo.h \
    graficadorhistograma.h \
    imagen.h \
    lut.h \
    negativo.h \
    pixel.h \
    procesadordeimagen.h \
    procesadorestadistico.h \
    sistema.h \
    ventanadegraficacion.h

QT -= gui

QT += widgets
LIBS += -lopengl32

CONFIG += c++11 console qt
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        archivoaic.cpp \
        archivopnm.cpp \
        espaciodetrabajo.cpp \
        gestordearchivos.cpp \
        imagen.cpp \
        main.cpp \
        pixel.cpp \
        ventanadegraficacion.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    archivoaic.h \
    archivopnm.h \
    espaciodetrabajo.h \
    gestordearchivos.h \
    imagen.h \
    pixel.h \
    ventanadegraficacion.h

QT       += core

QT       -= gui

TARGET = OIz_med_filter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp


INCLUDEPATH +=   D:\Nastya\Programs\Libriaries\CImg-2.1.2_pre102517 \
        D:\Nastya\Programs\Libriaries\armadillo-8.200.1\include

HEADERS +=

LIBS += -lAdvapi32 -lgdi32 -luser32 -lshell32 \
    -LD:\Nastya\Programs\Libriaries\armadillo-8.200.1\examples\lib_win64 \
    -llapack_win64_MT \
    -lblas_win64_MT

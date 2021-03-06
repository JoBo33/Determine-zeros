QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    determinezerosapplication.cpp \
    qcustomplot.cpp \
    tinyexpr.c \
    tinyexprwrapperlibrary.cpp

HEADERS += \
    ../../../../Downloads/QCustomPlot-source.tar/qcustomplot-source/qcustomplot.h \
    TestFunction.h \
    determinezerosapplication.h \
    qcustomplot.h \
    tinyexpr.h \
    tinyexprwrapperlibrary.h

FORMS += \
    determinezerosapplication.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

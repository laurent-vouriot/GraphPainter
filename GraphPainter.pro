QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cpp/graph/absgraph.cpp \
    cpp/drawer.cpp \
    cpp/main.cpp \
    cpp/mainwindow.cpp \
    cpp/graph/node.cpp \
    cpp/graph/nonorientedgraph.cpp \
    cpp/path/nonorientedpath.cpp \
    cpp/graph/orientedgraph.cpp \
    cpp/path/orientedpath.cpp

HEADERS += \
    headers/graph/absgraph.h \
    headers/drawer.h \
    headers/mainwindow.h \
    headers/graph/node.h \
    headers/graph/nonorientedgraph.h \
    headers/path/nonorientedpath.h \
    headers/graph/orientedgraph.h \
    headers/path/orientedpath.h \
    headers/path/strategypath.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

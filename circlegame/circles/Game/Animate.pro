TEMPLATE = app
CONFIG += console
#CONFIG -= app_bundle

#since we want to use qDebug, we
#will not subtract qt.
#CONFIG -= qt

SOURCES += main.cpp \
    game.cpp \
    particle.cpp \
    system.cpp \
    random.cpp \
    sidebar.cpp \
    MyVector.cpp

#LIBS += -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
##LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
#INCLUDEPATH += usr/local/include
#DEPENDPATH += usr/local/include
#------------------------------------------
##Add these lines for SFML:

CONFIG += c++11

LIBS += -L"..\..\SFML-2.0/bin"
LIBS += -L"..\..\SFML-2.0/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "..\..\SFML-2.0\include"
DEPENDPATH += "..\..\SFML-2.0\include"
#-----------------------------------------


HEADERS += \
    game.h \
    constants.h \
    particle.h \
    system.h \
    random.h \
    sidebar.h \
    MyVector.h

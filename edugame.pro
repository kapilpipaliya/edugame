TARGET = edugame

LIBS += \
    /usr/local/lib64/Urho3D/libUrho3D.a \
    -lpthread \
    -ldl \
    -lGL

QMAKE_CXXFLAGS += -std=c++11 -O2

INCLUDEPATH += \
    /usr/local/include/Urho3D/include \
    /usr/local/include/Urho3D/ThirdParty \

TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
  Components/dragablefish.h \
  Components/mycamera.h \
  Components/mylogo.h \
  Components/mytext.h \
  Components/myui.h \
    luckey.h \
    mastercontrol.h \
    sceneobject.h \

SOURCES += \
  Components/dragablefish.cpp \
  Components/mycamera.cpp \
  Components/mylogo.cpp \
  Components/mytext.cpp \
  Components/myui.cpp \
    luckey.cpp \
    mastercontrol.cpp \
    sceneobject.cpp \

DISTFILES += \
    LICENSE_TEMPLATE

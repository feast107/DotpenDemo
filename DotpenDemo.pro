#-------------------------------------------------
#
# Project created by QtCreator 2022-08-08T11:23:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DotpenDemo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Component/PenManager.cpp \
    Include/TQLCallBack.cpp \
    main.cpp \
    Drawer/StrokeDrawer.cpp \
    Form/SignForm.cpp \
    Component/FileManager.cpp \
    Form/MainForm.cpp

HEADERS += \
    Component/PenManager.h \
    Component/Helper.hpp \
    Include/hidapi.h \
    Include/TQLCallBack.h \
    Include/TQLComm.h \
    Models/StrokeModel.hpp \
    Models/StrokePointModel.hpp \
    Models/ResponseModel.hpp \
    Configuration/Strings.h \
    Drawer/PointDrawer.hpp \
    Drawer/StrokeDrawer.h \
    Form/SignForm.h \
    Component/FileManager.h \
    Form/MainForm.h \
    pch.h


FORMS += \
    Form/SignForm.ui \
    Form/MainForm.ui


#SDK头文件包含目录
INCLUDEPATH += $$PWD/Include
DEPENDPATH += $$PWD/Include

#工具头文件包含目录
INCLUDEPATH += $$PWD/../QtTool/Include
DEPENDPATH += $$PWD/../QtTool/Include


#在此修改宏以决定不同的链接
DEFINES += WIN


contains(DEFINES,MIPS){
#SDK动态链接库
unix:!macx: LIBS += -L$$PWD/SDK/MIPS/ -lTQLComm
#工具静态链接库
unix:!macx: LIBS += -L$$PWD/lib/MIPS/ -lQtTool
unix:!macx: PRE_TARGETDEPS += $$PWD/lib/MIPS/libQtTool.a
}

contains(DEFINES,x86){
#SDK动态链接库
unix:!macx: LIBS += -L$$PWD/SDK/x86/ -lTQLComm
#工具静态链接库
unix:!macx: LIBS += -L$$PWD/lib/x86/ -lQtTool
unix:!macx: PRE_TARGETDEPS += $$PWD/lib/x86/libQtTool.a
}

contains(DEFINES,WIN){
#SDK动态链接库
LIBS += -L$$PWD/SDK/WIN/ -lTQLComm
#工具静态链接库
win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/WIN/ -libQtTool
}

RESOURCES += \
    resource.qrc





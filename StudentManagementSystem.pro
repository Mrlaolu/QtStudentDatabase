QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog_addcourse.cpp \
    dialog_addpick.cpp \
    dialog_addstu.cpp \
    dialog_adduser.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    shell.c \
    sqlite3.c \
    stusqlite.cpp

HEADERS += \
    NameGen.h \
    dialog_addcourse.h \
    dialog_addpick.h \
    dialog_addstu.h \
    dialog_adduser.h \
    login.h \
    mainwindow.h \
    sqlite3.h \
    sqlite3ext.h \
    stusqlite.h

FORMS += \
    dialog_addcourse.ui \
    dialog_addpick.ui \
    dialog_addstu.ui \
    dialog_adduser.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

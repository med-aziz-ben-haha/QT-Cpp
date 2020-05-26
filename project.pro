QT       += core gui sql charts network texttospeech printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addconge.cpp \
    addemp.cpp \
    client.cpp \
    coli.cpp \
    conge.cpp \
    connection.cpp \
    connexion.cpp \
    courrier.cpp \
    deleteemp.cpp \
    equipement.cpp \
    exportexcelobject.cpp \
    gestion_coli_courrier.cpp \
    global.cpp \
    livraison.cpp \
    main.cpp \
    mainwindow.cpp \
    mytestmodel.cpp \
    peermanager.cpp \
    server.cpp \
    smtp.cpp \
    stat_cong.cpp \
    stat_emp.cpp \
    stat_etat.cpp \
    work_space.cpp

HEADERS += \
    addconge.h \
    addemp.h \
    client.h \
    coli.h \
    conge.h \
    connection.h \
    connexion.h \
    courrier.h \
    deleteemp.h \
    equipement.h \
    exportexcelobject.h \
    gestion_coli_courrier.h \
    global.h \
    livraison.h \
    mainwindow.h \
    mytestmodel.h \
    peermanager.h \
    server.h \
    smtp.h \
    stat_cong.h \
    stat_emp.h \
    stat_etat.h \
    work_space.h

FORMS += \
    addconge.ui \
    addemp.ui \
    deleteemp.ui \
    gestion_coli_courrier.ui \
    mainwindow.ui \
    stat_cong.ui \
    stat_emp.ui \
    stat_etat.ui \
    work_space.ui

requires(qtConfig(udpsocket))
requires(qtConfig(listwidget))

# install
target.path = $$[QT_INSTALL_EXAMPLES]/speech/hello_speak
INSTALLS += target

# install
target.path = $$[QT_INSTALL_EXAMPLES]/network/network-chat
INSTALLS += target



RESOURCES += \
    resources.qrc



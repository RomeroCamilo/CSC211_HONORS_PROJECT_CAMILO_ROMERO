QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutme.cpp \
    deficiency.cpp \
    importance.cpp \
    main.cpp \
    mainwindow.cpp \
    quiz.cpp \
    vitamina.cpp \
    vitaminb.cpp \
    vitaminc.cpp \
    vitamind.cpp \
    vitamine.cpp \
    vitamink.cpp

HEADERS += \
    aboutme.h \
    deficiency.h \
    importance.h \
    mainwindow.h \
    quiz.h \
    vitamina.h \
    vitaminb.h \
    vitaminc.h \
    vitamind.h \
    vitamine.h \
    vitamink.h

FORMS += \
    aboutme.ui \
    deficiency.ui \
    importance.ui \
    mainwindow.ui \
    quiz.ui \
    vitamina.ui \
    vitaminb.ui \
    vitaminc.ui \
    vitamind.ui \
    vitamine.ui \
    vitamink.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    TitleButton.qrc \
    aTitle.qrc \
    answersFold.qrc \
    backgrounds.qrc \
    buttons.qrc \
    buttons3.qrc \
    myFiles.qrc \
    orangeButton2.qrc \
    theBackgrounds.qrc \
    theFiles.qrc \
    titleA.qrc \
    vitaminA.qrc \
    vitaminA.qrc

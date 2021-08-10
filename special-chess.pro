QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bishop.cpp \
    cell.cpp \
    chessboard.cpp \
    chessman.cpp \
    globals.cpp \
    king.cpp \
    knight.cpp \
    login.cpp \
    main.cpp \
    game.cpp \
    pawn.cpp \
    queen.cpp \
    replacepawn.cpp \
    rook.cpp

HEADERS += \
    bishop.h \
    cell.h \
    chessboard.h \
    chessman.h \
    game.h \
    globals.h \
    king.h \
    knight.h \
    login.h \
    pawn.h \
    queen.h \
    replacepawn.h \
    rook.h

FORMS += \
    game.ui \
    login.ui \
    replacepawn.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    myres.qrc

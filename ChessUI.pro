#-------------------------------------------------
#
# Project created by QtCreator 2021-05-20T10:48:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChessUI
TEMPLATE = app
INCLUDEPATH += include

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17
QMAKE_CXXFLAGS += \
    -std=c++17

SOURCES += \
        src/bishop.cpp \
        src/board.cpp \
        src/boardscene.cpp \
        src/boardsquare.cpp \
        src/chess.cpp \
        src/cpuPlayer.cpp \
        src/emptyPiece.cpp \
        src/humanPlayer.cpp \
        src/king.cpp \
        src/knight.cpp \
        src/mainwindow.cpp \
        src/pawn.cpp \
        src/piece.cpp \
        src/pieceqt.cpp \
        src/queen.cpp \
        src/rook.cpp

HEADERS += \
        include/bishop.h \
        include/board.h \
        include/boardscene.h \
        include/boardsquare.h \
        include/cpuPlayer.h \
        include/emptyPiece.h \
        include/humanPlayer.h \
        include/king.h \
        include/knight.h \
        include/mainwindow.h \
        include/pawn.h \
        include/piece.h \
        include/pieceqt.h \
        include/position.h \
        include/queen.h \
        include/rook.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

FORMS +=

RESOURCES += \
    resources.qrc

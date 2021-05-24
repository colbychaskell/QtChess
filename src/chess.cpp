#include "board.h"
//#include "humanPlayer.h"
#include "cpuPlayer.h"
#include "piece.h"
#include "mainwindow.h"

#include <iostream>
#include <QApplication>
#include <QPushButton>


int main(int argc, char **argv) {

   QApplication app (argc,argv);


   MainWindow mainWindow(nullptr);
   mainWindow.setFixedSize(590, 500);

   mainWindow.show();

   return app.exec();
};

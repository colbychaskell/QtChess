#include "board.h"
//#include "humanPlayer.h"
#include <QApplication>
#include <QPushButton>
#include <iostream>

#include "cpuPlayer.h"
#include "mainwindow.h"
#include "piece.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  MainWindow mainWindow(nullptr);
  mainWindow.setFixedSize(590, 500);

  mainWindow.show();

  return app.exec();
};

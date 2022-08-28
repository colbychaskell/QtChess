#include "mainwindow.h"

int main(int argc, char **argv) {
  QApplication app(argc, argv);

  MainWindow mainWindow(nullptr);
  mainWindow.setFixedSize(590, 500);

  mainWindow.show();

  return app.exec();
};

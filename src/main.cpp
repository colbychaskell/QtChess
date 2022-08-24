#include <QApplication>
#include <QPushButton>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QPushButton button;
  button.setText("My Text");
  button.setToolTip("A Tooltip");
  button.show();

  return app.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app (argc, argv);
    QPushButton button;
    button.setText("My Text");
    button.setToolTip("A Tooltip");
    button.show();

    return app.exec();
}

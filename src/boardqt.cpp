#include "boardqt.h"

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QPainter>

BoardQt::BoardQt(QWidget *parent) : QWidget (parent) {

}

void BoardQt::paintEvent(QPaintEvent *event) {

    QRect wRect = rect();
    unsigned int cellSizeX = wRect.width() / 8;
    unsigned int cellSizeY = wRect.height() / 8;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(QColor(247,229,165));
    painter.drawRect(wRect);

    painter.setBrush(QColor(20,95,75));

    for(unsigned int j = 0; j < 8; j++) {
        for(unsigned int i = j % 2; i < 8; i+=2) {
            painter.drawRect(i * cellSizeX, j * cellSizeY, cellSizeX, cellSizeY);
        }
    }
}

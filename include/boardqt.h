#ifndef BOARDQT_H
#define BOARDQT_H

#include <QWidget>
#include <QPushButton>
#include <QApplication>

class BoardQt : public QWidget
{
    Q_OBJECT
public:
    explicit BoardQt(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);

};

#endif // BOARDQT_H

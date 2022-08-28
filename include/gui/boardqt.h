#ifndef BOARDQT_H
#define BOARDQT_H

#include <QApplication>
#include <QPushButton>
#include <QWidget>

class BoardQt : public QWidget {
  Q_OBJECT
 public:
  explicit BoardQt(QWidget *parent = nullptr);
  virtual void paintEvent(QPaintEvent *event);
};

#endif  // BOARDQT_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QBoxLayout>
#include <QMainWindow>
#include <QPainter>
#include <QProgressBar>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

#include "board.h"
#include "boardqt.h"
#include "boardscene.h"

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  Board& getBoard();

 private slots:
  void resign();
  void newWhite();
  void newBlack();

 private:
  BoardScene* board;
  QGraphicsView* graphicsView;
  QWidget* gridWidget;
  QGridLayout* gridLayout;
  QPushButton* resignButton;
  QPushButton* blackGame;
  QPushButton* whiteGame;
  // QPushButton
};

#endif  // MAINWINDOW_H

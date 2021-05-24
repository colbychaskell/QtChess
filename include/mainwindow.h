#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "boardqt.h"
#include "boardscene.h"
#include "board.h"

#include <QWidget>
#include <QPushButton>
#include <QApplication>
#include <QProgressBar>
#include <QSlider>
#include <QPainter>
#include <QBoxLayout>
#include <QMainWindow>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
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
    //QPushButton
};

#endif // MAINWINDOW_H

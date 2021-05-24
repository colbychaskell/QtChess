#include "mainwindow.h"
#include "boardqt.h"
#include "board.h"
#include <iostream>

#include <QGraphicsView>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) : QMainWindow (parent)
{
    this->gridWidget = new QWidget();
    this->gridLayout = new QGridLayout();
    gridWidget->setLayout(gridLayout);

    this->board = new BoardScene(this, Piece::Side::B);
    this->graphicsView = new QGraphicsView(this);
    graphicsView->setScene(board);
    gridLayout->addWidget(graphicsView, 0, 0, 8, 8);

    this->resignButton = new QPushButton(QString("Resign"), this);
    gridLayout->addWidget(resignButton, 8, 0, 1, 8);

    this->whiteGame = new QPushButton(QString("New Game as White"), this);
    gridLayout->addWidget(whiteGame, 9, 0, 1, 4);

    this->blackGame = new QPushButton(QString("New Game as Black"), this);
    gridLayout->addWidget(blackGame, 9, 4, 1, 4);


    this->setCentralWidget(gridWidget);
    connect(this->resignButton, SIGNAL(released()), this, SLOT(resign()));
    connect(this->whiteGame, SIGNAL(released()), this, SLOT(newWhite()));
    connect(this->blackGame, SIGNAL(released()), this, SLOT(newBlack()));

}

Board& MainWindow::getBoard() {
    return this->board->getBoard();
}
void MainWindow::resign() {
    this->board->resetBoard();
}

void MainWindow::newWhite() {
    BoardScene* tempBoard = new BoardScene(this, Piece::Side::W);
    this->graphicsView->setScene(tempBoard);
    delete this->board;
    this->board = tempBoard;
}

void MainWindow::newBlack() {
    BoardScene* tempBoard = new BoardScene(this, Piece::Side::B);
    this->graphicsView->setScene(tempBoard);
    delete this->board;
    this->board = tempBoard;
}

MainWindow::~MainWindow() {
    delete this->gridWidget;
    delete this->gridLayout;
    delete this->board;
    delete this->resignButton;
    delete this->whiteGame;
    delete this->blackGame;
}

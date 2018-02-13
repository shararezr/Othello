//
// Created by sam on 2/11/18.
//

#ifndef OTHELLO_GAMEWINDOW_H
#define OTHELLO_GAMEWINDOW_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QGridLayout>
#include <QDesktopWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets/QApplication>
#include <QGraphicsItem>
#include <MatrixElement.h>

const int WHITE=1;
const int BLACK=-1;

class MatrixElement;
class GameWindow : public QWidget{
Q_OBJECT
public:
    GameWindow(int,int);
    int wE,bE,gameState[10][10],playerTurn;
signals:
    void GameIsOver();
public slots:
    void setClick(int,int,int[10][10],bool);
private:
    QLabel *scoreHuman,*scoreCPU,*scoreTurn;
    MatrixElement *allItems[10][10];
    void initConfig();
    QTimer *timer;
    QGraphicsView *showView;
    QGraphicsScene *board;
    QImage *blackImage,*whiteImage;
    QLabel *scoreIcon;
    void refreshBoard();
    bool canISet(int,int,int,int);
    void changeElements(int,int,int,int,int[10][10],bool);
    void availableMoves();
    bool changedLastTime;
    QPair<int,int> aiNextMove();
};


#endif //OTHELLO_GAMEWINDOW_H

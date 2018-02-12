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


class GameWindow : public QWidget{
Q_OBJECT
public:
    GameWindow(int,int);

public slots:
    void setClick(int,int);
private:
    QLabel *scoreHuman,*scoreCPU,*scoreTurn;
    int gameState[10][10],playerTurn;
    MatrixElement *allItems[10][10];
    void initConfig();
    QTimer *timer;
    QGraphicsView *showView;
    QGraphicsScene *board;
    QImage *blackImage,*whiteImage;
    QLabel *scoreIcon;
    void refreshBoard();
    bool canISet(int,int,int,int);
    //void doTheTurn();
};


#endif //OTHELLO_GAMEWINDOW_H

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

class GameWindow : public QWidget{
Q_OBJECT
public:
    GameWindow(int,int);
    QLabel *scoreHuman,*scoreCPU;
};


#endif //OTHELLO_GAMEWINDOW_H

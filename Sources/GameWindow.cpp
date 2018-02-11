//
// Created by sam on 2/11/18.
//

#include "Headers/GameWindow.h"



GameWindow::GameWindow(int w, int h) {
    //Screen
    QRect rec = QApplication::desktop() -> screenGeometry();
    setGeometry(rec.width()/2 - w/2, rec.height() / 2 - h/2, w, h);
    setFixedSize(w,h);
    //view
    QGraphicsView *showView=new QGraphicsView(this);
    QGraphicsScene *board=new QGraphicsScene(showView);
    showView->setScene(board);
    showView->setSceneRect(0,0,h,h);
    board->setSceneRect(0,0,h,h);
    showView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showView->setRenderHint(QPainter::Antialiasing);
    //Label
    scoreHuman=new QLabel("Human:2");
    scoreCPU=new QLabel("CPU:2");
    QGridLayout *windowLayout=new QGridLayout(this);
    windowLayout->addWidget(showView,0,0,5,5);
    windowLayout->addWidget(scoreHuman,0,5,1,2);
    windowLayout->addWidget(scoreCPU,1,5,1,2);
    /*
    QLineF topLine(board->sceneRect().topLeft(), board->sceneRect().topRight());
    QLineF leftLine(board->sceneRect().topLeft(), board->sceneRect().bottomLeft());
    QLineF rightLine(board->sceneRect().topRight(), board->sceneRect().bottomRight());
    QLineF bottomLine(board->sceneRect().bottomLeft(), board->sceneRect().bottomRight());
    QPen myPen = QPen(Qt::red);
    board->addLine(topLine, myPen);
    board->addLine(leftLine, myPen);
    board->addLine(rightLine, myPen);
    board->addLine(bottomLine, myPen);
    */

    show();
}
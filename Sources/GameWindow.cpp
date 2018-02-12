//
// Created by sam on 2/11/18.
//

#include <QtCore/QTime>
#include "Headers/GameWindow.h"
#include <QTimer>
#include <QtGui/QPicture>
#include <QString>
#include <QDebug>

GameWindow::GameWindow(int w, int h) {
    //Screen
    QRect rec = QApplication::desktop() -> screenGeometry();
    setGeometry(rec.width()/2 - w/2, rec.height() / 2 - h/2, w+30, h+30);
    setFixedSize(w+30,h+30);
    //view
    showView=new QGraphicsView(this);
    board=new QGraphicsScene(showView);
    showView->setScene(board);
    showView->setSceneRect(0,0,h,h);
    board->setSceneRect(0,0,h,h);
    showView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showView->setRenderHint(QPainter::Antialiasing);
    //Label
    scoreHuman=new QLabel(this);
    scoreCPU=new QLabel(this);
    scoreTurn=new QLabel(this);
    blackImage = new QImage(QSize(50, 50), QImage::Format_RGB16);
    whiteImage = new QImage(QSize(50, 50), QImage::Format_RGB16);
    //whiteImage->load("white.png");
    whiteImage->load("src/white.png");
    blackImage->load("src/black.png");
    scoreIcon=new QLabel(this);
    //scoreIcon->setPixmap(QPixmap::fromImage(*whiteImage));
    //scoreIcon->setPixmap(QPixmap::fromImage(*blackImage));
    //Layout
    QGridLayout *windowLayout=new QGridLayout(this);
    windowLayout->addWidget(showView,0,0,5,5);
    windowLayout->addWidget(scoreHuman,0,5,1,2);
    windowLayout->addWidget(scoreCPU,1,5,1,2);
    windowLayout->addWidget(scoreIcon,2,5,2,2);
    windowLayout->addWidget(scoreTurn,3,7,1,2);
    setLayout(windowLayout);
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
    initConfig();
    show();
}

void GameWindow::initConfig() {
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            gameState[i][j]=0;
            allItems[i][j]=new MatrixElement();
            board->addItem(allItems[i][j]);
            allItems[i][j]->setPos(i*50,j*50);
            allItems[i][j]->xPos=i;
            allItems[i][j]->yPos=j;
            connect(allItems[i][j],SIGNAL(clickedOn(int,int)),this,SLOT(setClick(int,int)));
        }
    }
    //set initial elements
    allItems[3][3]->elementMode=WHITE;
    gameState[3][3]=WHITE;
    allItems[3][4]->elementMode=BLACK;
    gameState[3][4]=BLACK;
    allItems[4][3]->elementMode=BLACK;
    gameState[4][3]=BLACK;
    allItems[4][4]->elementMode=WHITE;
    gameState[4][4]=WHITE;
    //set timer
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    timer=new QTimer();
    connect(timer, SIGNAL(timeout()), showView, SLOT(update()));
    connect(timer, SIGNAL(timeout()), board, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), board, SLOT(update()));
    timer->start(1000 / 40);
    //set the turn
    playerTurn=WHITE;
    refreshBoard();
    //doTheTurn();
}
void GameWindow::refreshBoard() {
    if(playerTurn==WHITE){
        scoreTurn->setText("White Turn");
        scoreIcon->setPixmap(QPixmap::fromImage(*whiteImage));
    }else if(playerTurn==BLACK){
        scoreTurn->setText("Black Turn");
        scoreIcon->setPixmap(QPixmap::fromImage(*blackImage));
    }
    //scores
    int b=0,w=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            //qDebug()<<gameState[i][j]<<w<<b;
            MatrixElement *nowElement=allItems[i][j];
            if(gameState[i][j]==0){
                if(canISet(i,j,1,0)
                   || canISet(i,j,1,-1)
                   || canISet(i,j,0,-1)
                   || canISet(i,j,-1,-1)
                   || canISet(i,j,-1,0)
                   || canISet(i,j,-1,1)
                   || canISet(i,j,0,1)
                   || canISet(i,j,1,1)){
                    nowElement->isUsable=1;
                }else nowElement->isUsable=0;
            }else{
                if(gameState[i][j]==WHITE) w++;
                else if(gameState[i][j]==BLACK) b++;
                allItems[i][j]->isUsable=0;
            }
        }
    }
    //qDebug()<<gameState[3][3]<<WHITE<<BLACK;
    //qDebug()<<w<<b;
    //qDebug()<<allItems[4][2]->isUsable;
    //qDebug()<<allItems[4][2];
    scoreHuman->setText("Human(White) score:"+QString::number(w));
    scoreCPU->setText("CPU(Black) score:"+QString::number(b));
}
bool GameWindow::canISet(int x,int y,int p,int q){
    bool seenAnother=0,seenSelf=0;
    for(int i=x+p,j=y+q;(i>=0 && i<8) && (j>=0 && j<8);i+=p,j+=q){
        if(gameState[i][j]==playerTurn){
            seenSelf=1;
            break;
        }else if(gameState[i][j]==((-1)*playerTurn)){
            seenAnother=1;
        }else{
            break;
        }
    }
    if(seenAnother && seenSelf){
        return true;
    }
    return false;
}
void GameWindow::setClick(int xClick, int yClick) {
    MatrixElement *clickedElement=allItems[xClick][yClick];
    if(clickedElement->isUsable){
        gameState[xClick][yClick]=playerTurn;
        clickedElement->elementMode=playerTurn;
        //change All shits
        playerTurn*=-1;
    }
    refreshBoard();
}
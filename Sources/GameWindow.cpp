//
// Created by sam on 2/11/18.
//

#include <QtCore/QTime>
#include "Headers/GameWindow.h"
#include <QTimer>
#include <QtGui/QPicture>
#include <QString>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QtCore/QFileInfo>
#include <QUrl>
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
    qDebug()<<(QFileInfo("white.png").absoluteFilePath());
    whiteImage->load(QFileInfo("white.png").absoluteFilePath());
    blackImage->load(":/src/black.png");
    //QPixmap *whitePix=new QPixmap("")
    scoreIcon=new QLabel(this);
    scoreIcon->setPixmap(QPixmap::fromImage(*whiteImage));
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
    changedLastTime=1;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            gameState[i][j]=0;
            allItems[i][j]=new MatrixElement(this);
            board->addItem(allItems[i][j]);
            allItems[i][j]->setPos(i*50,j*50);
            allItems[i][j]->xPos=i;
            allItems[i][j]->yPos=j;
            //connect(allItems[i][j],SIGNAL(clickedOn(int,int)),this,SLOT(setClick(int,int)));
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
    wE=w;
    bE=b;
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
void GameWindow::changeElements(int x,int y,int p,int q,int myState[10][10],bool fakeMode=0){
    for(int i=x+p,j=y+q;(i>=0 && i<8) && (j>=0 && j<8);i+=p,j+=q){
        //if(gameState[i][j]==playerTurn) break;
        //gameState[i][j]=playerTurn;
        if(myState[i][j]==playerTurn) break;
        myState[i][j]=playerTurn;
        if(!fakeMode) allItems[i][j]->elementMode=playerTurn;
    }
}
void GameWindow::setClick(int xClick, int yClick,int theState[10][10],bool fakeModer=0) {
    MatrixElement *clickedElement=allItems[xClick][yClick];
    if(clickedElement->isUsable){

        if(canISet(xClick,yClick,1,0)) changeElements(xClick,yClick,1,0,theState,fakeModer);
        if(canISet(xClick,yClick,1,-1)) changeElements(xClick,yClick,1,-1,theState,fakeModer);
        if(canISet(xClick,yClick,0,-1)) changeElements(xClick,yClick,0,-1,theState,fakeModer);
        if(canISet(xClick,yClick,-1,-1)) changeElements(xClick,yClick,-1,-1,theState,fakeModer);

        if(canISet(xClick,yClick,-1,0)) changeElements(xClick,yClick,-1,0,theState,fakeModer);
        if(canISet(xClick,yClick,-1,1)) changeElements(xClick,yClick,-1,1,theState,fakeModer);
        if(canISet(xClick,yClick,0,1)) changeElements(xClick,yClick,0,1,theState,fakeModer);
        if(canISet(xClick,yClick,1,1)) changeElements(xClick,yClick,1,1,theState,fakeModer);

        //gameState[xClick][yClick]=playerTurn;
        theState[xClick][yClick]=playerTurn;
        if(!fakeModer){
            clickedElement->elementMode=playerTurn;
            playerTurn*=-1;
            refreshBoard();
            availableMoves();
        }
    }
}
void GameWindow::availableMoves(){
    int UsableNum=0,zero=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(allItems[i][j]->isUsable) UsableNum++;
            if(!gameState[i][j]) zero++;
        }
    }
    if(zero==0) emit GameIsOver();
    if(UsableNum==0){
        if(changedLastTime){
            changedLastTime=0;
            //QMessageBox *mb=new QMessageBox("move alert!",(playerTurn==WHITE?"White":"Black") + " can not move!")
            if(playerTurn==WHITE){
                QMessageBox *mb=new QMessageBox(this);
                mb->setWindowTitle("move alert!");
                mb->setText("White cant move.");
                mb->exec();
            }else if(playerTurn==BLACK){
                QMessageBox *mb=new QMessageBox(this);
                mb->setWindowTitle("move alert!");
                mb->setText("Black cant move.");
                mb->exec();
            }
            refreshBoard();
            //availableMoves();
        }else emit GameIsOver();
    }
    if(playerTurn==BLACK){
        QPair<int,int> myNextMove=aiNextMove();
        setClick(myNextMove.first,myNextMove.second,gameState,0);
    }
}
//AI
int arzesh[10][10]={
        {99, -8, 8,  6,  6,  8,  -8, 99},
        {-8, -24, -4, -3, -3, -4, -24, -8},
        {8, -4, 7,  4,  4,  7,  -4, 8},
        {6,  -3, 4,  0,  0,  4,  -3, 6},
        {6,  -3, 4,  0,  0,  4,  -3, 6},
        {8,  -4, 7,  4,  4,  7,  -4, 8},
        {-8, -24,  -4, -3, -3, -4, -24, -8},
        {99, -8, 8,  6,  6,  8,  -8, 99}
};
QPair<int,int> GameWindow::aiNextMove() {
    //QVector < QPair<int,int> > allPossibleElements;
    //QVector <int> possibleScore;
    int mxRes=0;
    QPair<int,int> mxR;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            int fakeState[10][10],wS=0,bS=0;
            for(int r=0;r<8;r++) for(int t=0;t<8;t++) fakeState[r][t]=gameState[r][t];
            if(allItems[i][j]->isUsable){
                //allPossibleElements.append(qMakePair(i,j));
                setClick(i,j,fakeState,1);
                for(int x=0;x<8;x++){
                    for(int y=0;y<8;y++){
                        if(fakeState[x][y]==WHITE) wS+=arzesh[x][y];
                        else if(fakeState[x][y]==BLACK) bS+=arzesh[x][y];
                    }
                }
                if(bS-wS>mxRes){
                    mxRes=bS-wS;
                    mxR=qMakePair(i,j);
                }
            }
        }
    }
    return mxR;
}

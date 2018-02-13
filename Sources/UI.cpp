//
// Created by sam on 2/11/18.
//

#include <Headers/SetWindow.h>
#include <Headers/GameWindow.h>
#include <QtWidgets/QMessageBox>
#include "Headers/UI.h"

UI::UI() {
    myFirstWindow=new SetWindow(200,200);
    connect(myFirstWindow,SIGNAL(readyToMake()),this,SLOT(acceptedMode()));
}
void UI::acceptedMode() {
    myFirstWindow->hide();
    mySecondWindow=new GameWindow(600,400);
    connect(mySecondWindow,SIGNAL(GameIsOver()),this,SLOT(newGame()));
}
void UI::newGame(){
    QMessageBox *mb=new QMessageBox();
    mb->setWindowTitle("Winner");
    if(mySecondWindow->wE > mySecondWindow->bE){
        mb->setText("White is winner.");
    }else if(mySecondWindow->wE < mySecondWindow->bE){
        mb->setText("Black is winner.");
    }else{
        mb->setText("It was a draw.");
    }
    mb->exec();
    //delete mySecondWindow;
    mySecondWindow->hide();
    myFirstWindow->show();
}
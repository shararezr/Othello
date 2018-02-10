//
// Created by sam on 2/11/18.
//


#include "Headers/SetWindow.h"

SetWindow::SetWindow(int w, int h) : modeTaken(0) {
    //Screen
    QRect rec = QApplication::desktop() -> screenGeometry();
    setGeometry(rec.width()/2 - w/2, rec.height() / 2 - h/2, w, h);
    //setFixedSize(w,h);
    //Buttons
    QPushButton *go = new QPushButton("Ready!", this);
    connect(go, SIGNAL(clicked()), this, SLOT(makeIt()));
    //Labels
    //QLabel *myMode=new QLabel("Choose Mode:",this);
    //Radios
    playingCPU=new QRadioButton("vs CPU",this);
    playingHuman=new QRadioButton("vs Human",this);
    playingCPU->setChecked(true);
    QGroupBox *myBox=new QGroupBox(this);
    myBox->setFocus();
    QVBoxLayout *playingOPT=new QVBoxLayout(this);
    playingOPT->addWidget(playingCPU);
    playingOPT->addWidget(playingHuman);
    myBox->setLayout(playingOPT);
    myBox->setTitle("Choose Mode:");
    myBox->setStyleSheet("border:none");
    myBox->show();
    //Layout
    QGridLayout *mainLayoutOfSW=new QGridLayout();
    //mainLayoutOfSW->addWidget(myMode,0,0,1,2);
    mainLayoutOfSW->addWidget(go,0,2,1,2);
    mainLayoutOfSW->addWidget(myBox,0,0,2,2);
    setWindowTitle("options");
    setLayout(mainLayoutOfSW);
    show();
}
void SetWindow::makeIt() {
    if(playingCPU->isChecked()) emit readyToMake();
}
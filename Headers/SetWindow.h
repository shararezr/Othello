//
// Created by sam on 2/11/18.
//

#ifndef OTHELLO_SETWINDOW_H
#define OTHELLO_SETWINDOW_H

#include <QWidget>
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include <QPushButton>
#include <QLabel>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QGroupBox>

class SetWindow: public QWidget {
Q_OBJECT
public:
    SetWindow(int,int);
    quint16 modeTaken;
    QRadioButton *playingCPU;
    QRadioButton *playingHuman
public slots:
    void makeIt();
signals:
    void readyToMake();
};


#endif //OTHELLO_SETWINDOW_H

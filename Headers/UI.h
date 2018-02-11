//
// Created by sam on 2/11/18.
//

#ifndef OTHELLO_UI_H
#define OTHELLO_UI_H


#include <QtCore/QtCore>
#include <QObject>
#include "Headers/SetWindow.h"
#include "Headers/GameWindow.h"

class UI: public QObject {
Q_OBJECT
public:
    UI();

public slots:
    void acceptedMode();

private:
    SetWindow *myFirstWindow;
    GameWindow *mySecondWindow;
};


#endif //OTHELLO_UI_H

//
// Created by sam on 2/11/18.
//

#include <Headers/SetWindow.h>
#include <Headers/GameWindow.h>
#include "Headers/UI.h"

UI::UI() {
    myFirstWindow=new SetWindow(200,200);
    connect(myFirstWindow,SIGNAL(readyToMake()),this,SLOT(acceptedMode()));
}
void UI::acceptedMode() {
    myFirstWindow->hide();
    mySecondWindow=new GameWindow(600,400);

}
//
// Created by sam on 2/11/18.
//

#include <Headers/SetWindow.h>
#include "Headers/UI.h"
UI::UI() {
    SetWindow *myFirstWindow=new SetWindow(200,200);
    //connect(myFirstWindow,SIGNAL(readyToMake()),this,SLOT());

}
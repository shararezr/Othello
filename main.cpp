
#include <QApplication>
#include <Headers/SetWindow.h>

int main(int argc, char **argv) {
    QApplication *app = new QApplication(argc, argv);
    SetWindow *chooseOpt=new SetWindow(200,200);
    app->exec();
    return 0;
}
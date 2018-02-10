
#include <QApplication>
#include <Headers/UI.h>

int main(int argc, char **argv) {
    QApplication *app = new QApplication(argc, argv);
    UI *myUserInterface=new UI();
    app->exec();
    return 0;
}
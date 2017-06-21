#include "loginwindows.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    LoginWindows w;
    w.setWindowTitle("Nuevas Solicitudes");
    w.show();

    return a.exec();
}

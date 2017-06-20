#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Nuevas Solicitudes");
    w.show();

    return a.exec();
}

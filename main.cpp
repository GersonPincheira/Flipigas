#include "mainwindow.h"
#include <QApplication>
#include <camion.h>


/*Solicitud NewSolicitud(){
    int cantidad=0;
    int kilos;
    string tipo;
    cout<<"ingrese cantidad de cilindros: ";
    cin >> cantidad;
    for(int i =0; i<cantidad;i++){
        cout<<"de cuantos kilos es su cilindro"+to_string(i);
        cin>>kilos;

    }
}*/

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

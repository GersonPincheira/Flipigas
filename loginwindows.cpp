#include "loginwindows.h"
#include "ui_loginwindows.h"

LoginWindows::LoginWindows(QWidget *parent,deque<Solicitud> *s,deque<Camion> *c) :
    QMainWindow(parent),
    ui(new Ui::LoginWindows)
{
    ui->setupUi(this);
    solicitudes = s;
    camiones = c;

}

LoginWindows::~LoginWindows()
{
    delete ui;
}

void LoginWindows::on_pushButton_clicked()
{
    string user = ui->user->text().toLocal8Bit().constData();
    string pass = ui->pass->text().toLocal8Bit().constData();
    fstream fichero;
    string archivo="/home/gerson/TAREA1/Tarea1-TEL102/Operadores.txt";    //RUTA DEPENDE DE CADA UNO
    string user1;
    string pass1;
    string linea;
    int verificar = 0;
    fichero.open(archivo.c_str(),ios::in);
    if(fichero.is_open()){
        while(!fichero.eof()){
            getline(fichero,linea);
            user1= linea.substr(0,linea.find(';'));
            pass1= linea.substr(linea.find(';')+1,linea.size());
            if(user1==user && pass==pass1) verificar=1;
        } fichero.close();
    }else{
    cout << "no se pudo abrir archivo"<< endl;
    }
    archivo = "/home/gerson/TAREA1/Tarea1-TEL102/Camioneros.txt";
    fichero.open(archivo.c_str(),ios::in);
    if(fichero.is_open()){
        while(!fichero.eof()){
            getline(fichero,linea);
            user1= linea.substr(0,linea.find(';'));
            pass1= linea.substr(linea.find(';')+1,linea.size());
            if(user1==user && pass==pass1) verificar=2;
        } fichero.close();
    }else{
    cout << "no se pudo abrir archivo"<< endl;
    }
    //agregar ADMINISTRADOR.......
    if (!user.empty() && !pass.empty()){
        if(verificar==1){
            MainWindow *ventana = new MainWindow(0,solicitudes,camiones);
            ventana->show();
            close();
        }else if(verificar==2){
            CamionWindows *ventana = new CamionWindows(0,solicitudes,camiones);
            ventana->show();
         close();
        }else{
            QMessageBox Error;
            Error.setWindowTitle("Ingreso Incorrecto");
            Error.setText("Error al ingresar\n"
                      "Por Favor intente nuevamente");
            Error.exec();
        }
    }else{
            QMessageBox Error;
            Error.setWindowTitle("Ingreso Incorrecto");
            Error.setText("Error al ingresar\n"
                      "Por Favor intente nuevamente");
            Error.exec();
        }
}


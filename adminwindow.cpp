#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <string>
#include "inventario.h"
AdminWindow::AdminWindow(QWidget *parent,deque<Solicitud> *s,deque<Camion> *c) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    solicitudes=s;
    camiones=c;
    LoginWindows *ventana = new LoginWindows(0,solicitudes,camiones);
    connect(ui->actionCerrar_Sesion,SIGNAL(triggered()),ventana,SLOT(show()));
    connect(ui->actionCerrar_Sesion,SIGNAL(triggered()),this,SLOT(close()));
    deque<Solicitud>::iterator iter;
    int actual = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(actual);
    for(iter=solicitudes->begin();iter!=solicitudes->end();iter++){
        Solicitud localSolicitud = *iter;
        deque<Cilindro>::iterator itau;
        std::string ubicacionLocal = localSolicitud.getUbicacion();
        if (ubicacionLocal!=""){
            ui->tableWidget->setItem(actual,0,new QTableWidgetItem(QString::fromStdString(ubicacionLocal)));
            for(itau=localSolicitud.pedidos.begin();itau!=localSolicitud.pedidos.end();itau++){
                Cilindro dato=*itau;
            ui->tableWidget->setItem(actual,1,new QTableWidgetItem(QString::fromStdString(dato.gettipo())));
            ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(dato.getkilos())));
            ui->tableWidget->setItem(actual,3,new QTableWidgetItem(QString::number(localSolicitud.CantidadDeCilindros())));
            bool estado = localSolicitud.getentregado();
            string state = estado ? "Si" : "No";
            ui->tableWidget->setItem(actual,4,new QTableWidgetItem(QString::fromStdString(state)));
            actual = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(actual);
        }
        }

    }
    ui->VentasBox->setText(QString::number(invent.ventas));
    ui->utilidadBox->setText(QString::number(invent.utilidades));
    ui->gastosBox->setText(QString::number(invent.gastos));
    ui->cantidadCilindrosBox->setText(QString::number(invent.cilindrostotal));
    int actual2 = ui->tableWidget_2->rowCount();
    ui->tableWidget_2->insertRow(actual2);
    ui->tableWidget_2->setItem(actual2,0,new QTableWidgetItem("Catalitico"));
    ui->tableWidget_2->setItem(actual2,1,new QTableWidgetItem("5"));
    ui->tableWidget_2->setItem(actual2,2,new QTableWidgetItem(QString::number(invent.catalitico5)));
    ui->tableWidget_2->insertRow(actual2);
    ui->tableWidget_2->setItem(actual2,0,new QTableWidgetItem("Catalitico"));
    ui->tableWidget_2->setItem(actual2,1,new QTableWidgetItem("11"));
    ui->tableWidget_2->setItem(actual2,2,new QTableWidgetItem(QString::number(invent.catalitico11)));
    ui->tableWidget_2->insertRow(actual2);
    ui->tableWidget_2->setItem(actual2,0,new QTableWidgetItem("Catalitico"));
    ui->tableWidget_2->setItem(actual2,1,new QTableWidgetItem("15"));
    ui->tableWidget_2->setItem(actual2,2,new QTableWidgetItem(QString::number(invent.catalitico15)));
    ui->tableWidget_2->insertRow(actual2);
    ui->tableWidget_2->setItem(actual2,0,new QTableWidgetItem("Catalitico"));
    ui->tableWidget_2->setItem(actual2,1,new QTableWidgetItem("45"));
    ui->tableWidget_2->setItem(actual2,2,new QTableWidgetItem(QString::number(invent.catalitico45)));
    ui->tableWidget_2->insertRow(actual2);
    ui->tableWidget_2->setItem(actual2,0,new QTableWidgetItem("No Catalitico"));
    ui->tableWidget_2->setItem(actual2,1,new QTableWidgetItem("5"));
    ui->tableWidget_2->setItem(actual2,2,new QTableWidgetItem(QString::number(invent.nocatalitico5)));
    ui->tableWidget_2->insertRow(actual2);
    ui->tableWidget_2->setItem(actual2,0,new QTableWidgetItem("No Catalitico"));
    ui->tableWidget_2->setItem(actual2,1,new QTableWidgetItem("11"));
    ui->tableWidget_2->setItem(actual2,2,new QTableWidgetItem(QString::number(invent.nocatalitico11)));
    ui->tableWidget_2->insertRow(actual2);
    ui->tableWidget_2->setItem(actual2,0,new QTableWidgetItem("No Catalitico"));
    ui->tableWidget_2->setItem(actual2,1,new QTableWidgetItem("15"));
    ui->tableWidget_2->setItem(actual2,2,new QTableWidgetItem(QString::number(invent.nocatalitico15)));
    ui->tableWidget_2->insertRow(actual2);
    ui->tableWidget_2->setItem(actual2,0,new QTableWidgetItem("No Catalitico"));
    ui->tableWidget_2->setItem(actual2,1,new QTableWidgetItem("45"));
    ui->tableWidget_2->setItem(actual2,2,new QTableWidgetItem(QString::number(invent.nocatalitico45)));



}

AdminWindow::~AdminWindow()
{
    delete ui;
}

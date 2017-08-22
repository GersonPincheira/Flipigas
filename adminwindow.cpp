#include "adminwindow.h"
#include "ui_adminwindow.h"

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

}

AdminWindow::~AdminWindow()
{
    delete ui;
}

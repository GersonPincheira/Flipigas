#include "camionwindows.h"
#include "ui_camionwindows.h"

CamionWindows::CamionWindows(QWidget *parent,deque<Solicitud> *s,deque<Camion> *c) :
    QMainWindow(parent),
    ui(new Ui::CamionWindows)
{
    ui->setupUi(this);
    solicitudes=s;
    camiones=c;
    LoginWindows *ventana = new LoginWindows(0,solicitudes,camiones);
    string asignado="";
    if(camiones->empty()){
        if(!solicitudes->empty()){
            Solicitud n = solicitudes->front();
            asignado = n.getUbicacion();
        }else{
            QMessageBox mensaje;
            mensaje.setWindowTitle("Sin Solicitudes ");
            mensaje.setText("No tenemos Pedidos por el momento, por lo que no hay nuevas entregas que realizar\nVuelve Mas Tarde");
            mensaje.exec();
        }
    }else{
        if(!solicitudes->empty()){
            deque<Solicitud>::iterator iter;
            for(iter=solicitudes->begin();iter!=solicitudes->end();iter++){
                Solicitud d = *iter;
                if(!d.asignado){
                    asignado=d.getUbicacion();
                    break;
                }
            }
        }else{
            QMessageBox mensaje;
            mensaje.setWindowTitle("Sin Solicitudes ");
            mensaje.setText("No tenemos Pedidos por el momento, por lo que no hay nuevas entregas que realizar\nVuelve Mas Tarde");
            mensaje.exec();
        }
    }
    //crear camion
    if(!solicitudes->empty() && asignado!=""){
        int cantidad=0;
        deque<Solicitud> carga;
        deque<Solicitud>::iterator iter;
        for(iter=solicitudes->begin();iter!=solicitudes->end();iter++){
            Solicitud d=*iter;
            if(!d.asignado && d.getUbicacion()==asignado){
                d.asignado=1;
                carga.push_back(d);
                cantidad+= d.CantidadDeCilindros();
                if(cantidad == Z) break;
            }
        }
        Camion *ncamion;
        if(cantidad < X) ncamion = new Camion(X,asignado,carga);
        else if(cantidad < Y) ncamion = new Camion(Y,asignado,carga);
        else ncamion = new Camion(Z,asignado,carga);
        camiones->push_front(*ncamion);
        camion=*ncamion;

    }

    //vista camion
    Camion Usercamion = camiones->front();
    Solicitud solicitud = Usercamion.carga.front();
    ui->ID->setText(QString::number(solicitud.getID()));
    ui->cerro->setText(QString::fromStdString(Usercamion.getUbicacion()));
    int actual = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(actual);
    deque<Cilindro>::iterator iter;
    int cantidad5k=0; int cantidad11k=0; int cantidad15k=0; int cantidad45k=0;
    int ncantidad5k=0; int ncantidad11k=0; int ncantidad15k=0; int ncantidad45k=0;
    for(iter=solicitud.pedidos.begin();iter!=solicitud.pedidos.end();iter++){
        Cilindro dato=*iter;
        if(dato.gettipo()=="Catalitico"){
            if(dato.getkilos()==5) cantidad5k++;
            else if(dato.getkilos()==11) cantidad11k++;
            else if(dato.getkilos()==15) cantidad15k++;
            else cantidad45k++;
        }else{
            if(dato.getkilos()==5) ncantidad5k++;
            else if(dato.getkilos()==11) ncantidad11k++;
            else if(dato.getkilos()==15) ncantidad15k++;
            else ncantidad45k++;
        }
    }
    if(cantidad5k!=0){
        ui->tableWidget->setItem(actual,0,new QTableWidgetItem("Catalitico"));
        ui->tableWidget->setItem(actual,1,new QTableWidgetItem("5Kg"));
        ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(cantidad5k)));
        actual = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(actual);
    }if(cantidad11k!=0){
        ui->tableWidget->setItem(actual,0,new QTableWidgetItem("Catalitico"));
        ui->tableWidget->setItem(actual,1,new QTableWidgetItem("11Kg"));
        ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(cantidad11k)));
        actual = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(actual);
    }if(cantidad15k!=0){
        ui->tableWidget->setItem(actual,0,new QTableWidgetItem("Catalitico"));
        ui->tableWidget->setItem(actual,1,new QTableWidgetItem("15Kg"));
        ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(cantidad15k)));
        actual = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(actual);
    }if(cantidad45k!=0){
        ui->tableWidget->setItem(actual,0,new QTableWidgetItem("Catalitico"));
        ui->tableWidget->setItem(actual,1,new QTableWidgetItem("45Kg"));
        ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(cantidad45k)));
        actual = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(actual);
    }if(ncantidad5k!=0){
        ui->tableWidget->setItem(actual,0,new QTableWidgetItem("No Catalitico"));
        ui->tableWidget->setItem(actual,1,new QTableWidgetItem("5Kg"));
        ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(ncantidad5k)));
        actual = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(actual);
    }if(ncantidad11k!=0){
        ui->tableWidget->setItem(actual,0,new QTableWidgetItem("No Catalitico"));
        ui->tableWidget->setItem(actual,1,new QTableWidgetItem("11Kg"));
        ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(ncantidad11k)));
        actual = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(actual);
    }if(ncantidad15k!=0){
        ui->tableWidget->setItem(actual,0,new QTableWidgetItem("No Catalitico"));
        ui->tableWidget->setItem(actual,1,new QTableWidgetItem("15Kg"));
        ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(ncantidad15k)));
        actual = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(actual);
    }if(ncantidad45k!=0){
        ui->tableWidget->setItem(actual,0,new QTableWidgetItem("No Catalitico"));
        ui->tableWidget->setItem(actual,1,new QTableWidgetItem("45Kg"));
        ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(ncantidad45k)));
        actual = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(actual);
    }
    if(!(cantidad5k==cantidad11k==cantidad15k==cantidad45k==ncantidad5k==ncantidad11k==ncantidad15k==ncantidad45k==0))
        ui->tableWidget->removeRow(actual);
    connect(ui->actionCerrar_Session,SIGNAL(triggered()),ventana,SLOT(show()));
    connect(ui->actionCerrar_Session,SIGNAL(triggered()),this,SLOT(close()));


}

CamionWindows::~CamionWindows()
{
    delete ui;
}

void CamionWindows::on_entregado_clicked()
{
    for(int i=ui->tableWidget->rowCount();i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
    bool verificar=0;
    bool nsolicitud=0;
    int dato=0;
    Solicitud solicitud;
    deque<Solicitud>::iterator iterator;
    for(iterator=camion.carga.begin();iterator!=camion.carga.end();iterator++){
        Solicitud s = *iterator;        
        cout << s.getID() <<endl;
        cout << s.getentregado()<< verificar <<endl;
        if(s.getentregado()==0 && verificar==0){
            camion.carga.at(dato).setEntregado(1);
            verificar=1;
        }
        else if(s.getentregado()==0 && verificar==1){
            solicitud=s;
            nsolicitud=1;
            break;
        }if(dato+1==camion.carga.size()){
                QMessageBox mensaje;
                mensaje.setWindowTitle("Sin Solicitudes ");
                mensaje.setText("Ya completo todos los pedidos asignados");
                mensaje.exec();
                break;
         }
        dato++;
    }

    if(nsolicitud==1){
        ui->ID->setText(QString::number(solicitud.getID()));
        int actual = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(actual);
        deque<Cilindro>::iterator iter;
        int cantidad5k=0; int cantidad11k=0; int cantidad15k=0; int cantidad45k=0;
        int ncantidad5k=0; int ncantidad11k=0; int ncantidad15k=0; int ncantidad45k=0;
        for(iter=solicitud.pedidos.begin();iter!=solicitud.pedidos.end();iter++){
            Cilindro dato=*iter;
            if(dato.gettipo()=="Catalitico"){
                if(dato.getkilos()==5) cantidad5k++;
                else if(dato.getkilos()==11) cantidad11k++;
                else if(dato.getkilos()==15) cantidad15k++;
                else cantidad45k++;
            }else{
                if(dato.getkilos()==5) ncantidad5k++;
                else if(dato.getkilos()==11) ncantidad11k++;
                else if(dato.getkilos()==15) ncantidad15k++;
                else ncantidad45k++;
            }
        }
        if(cantidad5k!=0){
            ui->tableWidget->setItem(actual,0,new QTableWidgetItem("Catalitico"));
            ui->tableWidget->setItem(actual,1,new QTableWidgetItem("5Kg"));
            ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(cantidad5k)));
            actual = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(actual);
        }if(cantidad11k!=0){
            ui->tableWidget->setItem(actual,0,new QTableWidgetItem("Catalitico"));
            ui->tableWidget->setItem(actual,1,new QTableWidgetItem("11Kg"));
            ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(cantidad11k)));
            actual = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(actual);
        }if(cantidad15k!=0){
            ui->tableWidget->setItem(actual,0,new QTableWidgetItem("Catalitico"));
            ui->tableWidget->setItem(actual,1,new QTableWidgetItem("15Kg"));
            ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(cantidad15k)));
            actual = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(actual);
        }if(cantidad45k!=0){
            ui->tableWidget->setItem(actual,0,new QTableWidgetItem("Catalitico"));
            ui->tableWidget->setItem(actual,1,new QTableWidgetItem("45Kg"));
            ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(cantidad45k)));
            actual = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(actual);
        }if(ncantidad5k!=0){
            ui->tableWidget->setItem(actual,0,new QTableWidgetItem("No Catalitico"));
            ui->tableWidget->setItem(actual,1,new QTableWidgetItem("5Kg"));
            ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(ncantidad5k)));
            actual = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(actual);
        }if(ncantidad11k!=0){
            ui->tableWidget->setItem(actual,0,new QTableWidgetItem("No Catalitico"));
            ui->tableWidget->setItem(actual,1,new QTableWidgetItem("11Kg"));
            ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(ncantidad11k)));
            actual = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(actual);
        }if(ncantidad15k!=0){
            ui->tableWidget->setItem(actual,0,new QTableWidgetItem("No Catalitico"));
            ui->tableWidget->setItem(actual,1,new QTableWidgetItem("15Kg"));
            ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(ncantidad15k)));
            actual = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(actual);
        }if(ncantidad45k!=0){
            ui->tableWidget->setItem(actual,0,new QTableWidgetItem("No Catalitico"));
            ui->tableWidget->setItem(actual,1,new QTableWidgetItem("45Kg"));
            ui->tableWidget->setItem(actual,2,new QTableWidgetItem(QString::number(ncantidad45k)));
            actual = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(actual);
        }
        if(!(cantidad5k==cantidad11k==cantidad15k==cantidad45k==ncantidad5k==ncantidad11k==ncantidad15k==ncantidad45k==0))
            ui->tableWidget->removeRow(actual);
    }


}

#include "mainwindow.h"
#include "ui_mainwindow.h"

deque<Solicitud> solicitudes;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList cerritos;
    cerritos <<"Seleccione cerro"<< "Alegre"<< "Barón"<< "Blanco"<< "Bellavista"<< "Concepción"<< "Cordillera"<< "Delicias"<< "El Litre"<< "El Molino"<< "Esperanza"<< "Jiménez"<< "Larraín"<< "La Cruz"<< "La Cárcel"<< "La Florida"<< "La Merced"<< "La Virgen"<< "Las Cañas"<< "Las Jarcias"<< "Las Monjas"<< "Los Placeres"<< "Loceras"<< "Lecheros"<< "Mariposas"<< "Mesilla"<< "Miraflores"<< "O'Higgins"<< "Pajonal"<< "Panteón"<< "Playa Ancha"<< "Perdices"<< "Polanco"<< "Ramaditas"<< "Reina Victoria"<< "Rodelillo"<< "Rocuant"<< "San Juan de Dios"<< "Santo Domingo"<< "San Francisco"<< "Toro"<< "Yungay";
    ui->cerros->addItems(cerritos);
    QStringList mPagos;
    mPagos <<"Seleccione medio de pago"<<"Cheque"<<"Efectivo"<<"Debito"<<"Credito";
    ui->Mcash->addItems(mPagos);
    QComboBox *combo1= new QComboBox();
    QStringList T;
    T << "Catalitico"<<"No Catalitico";
    combo1->addItems(T);
    QComboBox *combo2= new QComboBox();
    T.clear();
    T << "5 kg"<<"11 kg"<< "15 kg"<<"45 kg";
    combo2->addItems(T);
    QSpinBox *cantidad = new QSpinBox();
    ui->tableWidget->setCellWidget(0, 0,combo1);
    ui->tableWidget->setCellWidget(0,1,combo2);
    ui->tableWidget->setCellWidget(0,2,cantidad);
    if(solicitudes.empty()) ui->id_venta->setText("0001");
    else ui->id_venta->setText(QString::number(solicitudes.back().getID()+1));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    string rut = ui->rut->text().toLocal8Bit().constData();
    string nombre = ui->name_user->text().toLocal8Bit().constData();
    string cerro = ui->cerros->currentText().toLocal8Bit().constData();
    string pago = ui->Mcash->currentText().toLocal8Bit().constData();
    if(nombre!="" && cerro!="Seleccione cerro" && pago!="Seleccione medio de pago"){
        deque <Cilindro>cilindros;
        int precio=0;
        for(int i=0; i<ui->tableWidget->rowCount();i++){
            QComboBox *tipo =(QComboBox*) ui->tableWidget->cellWidget(i,0);
            QComboBox *tam = (QComboBox*) ui->tableWidget->cellWidget(i,1);
            QSpinBox *cantidad =(QSpinBox*) ui->tableWidget->cellWidget(i,2);
            string tipoDato = tipo->currentText().toLocal8Bit().constData();
            string tamDato = tam->currentText().toLocal8Bit().constData();
            string cantDato = cantidad->text().toLocal8Bit().constData();
            for(int n=0; n<stoi(cantDato);n++){
                Cilindro *h=new Cilindro(stoi(tamDato.substr(0,2)),tipoDato);
                precio+=h->precio();
                cilindros.push_back(*h);
            }
        }
        string ID_venta = ui->id_venta->text().toLocal8Bit().constData();
        Solicitud *s = new Solicitud(cilindros,cerro,pago,nombre,rut,0,stoi(ID_venta),precio);
        solicitudes.push_back(*s);
        ui->id_venta->setText(QString::number(stoi(ID_venta)+1));
        QMessageBox mensaje;
        mensaje.setWindowTitle(" ");
        mensaje.setText("Solicitud ingresada correctamente\n"
                       "Total a pagar $"+QString::number(precio)+"\n"
                       "Tiempo de espera estimado:"+QString::number(s->getTiempoDeEntrega())+" Minutos");
        mensaje.exec();
    }else{
        QMessageBox Error;
        Error.setText("Rellene bien los campos");
        Error.setWindowTitle("Error");
        Error.exec();
    }
    ui->cerros->setCurrentIndex(0);
    ui->Mcash->setCurrentIndex(0);
    int actual =  ui->tableWidget->rowCount();
    for(actual;actual>=0;actual--){
        ui->tableWidget->removeRow(actual);
    }
    MainWindow::on_pushButton_2_clicked();
    ui->name_user->clear();
    ui->rut->clear();


}


void MainWindow::on_pushButton_2_clicked()
{
    int actual = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(actual);
    QComboBox *combo1= new QComboBox();
    QStringList T;
    T << "Catalitico"<<"No Catalitico";
    combo1->addItems(T);
    QComboBox *combo2= new QComboBox();
    T.clear();
    T << "5 kg"<<"11 kg"<< "15 kg"<<"45 kg";
    combo2->addItems(T);
    QSpinBox *cantidad = new QSpinBox();
    ui->tableWidget->setCellWidget(actual, 0,combo1);
    ui->tableWidget->setCellWidget(actual,1,combo2);
    ui->tableWidget->setCellWidget(actual,2,cantidad);
}

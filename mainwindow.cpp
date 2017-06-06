#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <strings.h>
#include <camion.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString e1 = ui->tamC->currentText();
    string tamC = e1.toLocal8Bit().constData();
    QString e2 = ui->tamNC->currentText();
    string tamNC = e2.toLocal8Bit().constData();
    QString e3 = ui->canC->text();
    string canC = e3.toLocal8Bit().constData();
    QString e4 = ui->canNC->text();
    string canNC = e4.toLocal8Bit().constData();
    ui->label_3->setText(QString::fromStdString("Solicitud Ingresada satisfactoriamente!!"));
}

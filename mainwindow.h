#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QStringList>
#include <QMessageBox>
#include <QComboBox>
#include <QSpinBox>
#include <string>
#include <string.h>
#include <camion.h>
#include <fstream>
#include <loginwindows.h>
#include <inventario.h>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent,deque<Solicitud> *s,deque<Camion> *c);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    deque<Solicitud> *solicitudes;
    deque<Camion> *camiones;
};

#endif // MAINWINDOW_H

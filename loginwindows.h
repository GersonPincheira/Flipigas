#ifndef LOGINWINDOWS_H
#define LOGINWINDOWS_H

#include<mainwindow.h>
#include<camionwindows.h>
#include<adminwindow.h>

namespace Ui {
class LoginWindows;
}

class LoginWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindows(QWidget *parent,deque<Solicitud> *s,deque<Camion> *c);
    ~LoginWindows();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginWindows *ui;
    deque<Solicitud> *solicitudes;
    deque<Camion> *camiones;
};

#endif // LOGINWINDOWS_H

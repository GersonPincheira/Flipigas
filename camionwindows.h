#ifndef CAMIONWINDOWS_H
#define CAMIONWINDOWS_H

#include <QMainWindow>
#include <mainwindow.h>

namespace Ui {
class CamionWindows;
}

class CamionWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit CamionWindows(QWidget *parent,deque<Solicitud> *s,deque<Camion> *c);
    ~CamionWindows();

private slots:
    void on_entregado_clicked();

private:
    Ui::CamionWindows *ui;
    deque<Solicitud> *solicitudes;
    deque<Camion> *camiones;
    Camion camion;
};

#endif // CAMIONWINDOWS_H

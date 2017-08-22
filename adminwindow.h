#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <mainwindow.h>
#include <inventario.h>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent,deque<Solicitud> *s,deque<Camion> *c);
    ~AdminWindow();

private:
    Ui::AdminWindow *ui;
    deque<Solicitud> *solicitudes;
    deque<Camion> *camiones;
    Camion camion;
    Inventario invent;
};

#endif // ADMINWINDOW_H

// private:
//     Camion camion;
// };

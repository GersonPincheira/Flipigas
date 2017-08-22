#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <mainwindow.h>

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
};

#endif // ADMINWINDOW_H

// private:
//     Camion camion;
// };

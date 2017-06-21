#ifndef LOGINWINDOWS_H
#define LOGINWINDOWS_H

#include<mainwindow.h>

namespace Ui {
class LoginWindows;
}

class LoginWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindows(QWidget *parent = 0);
    ~LoginWindows();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginWindows *ui;
};

#endif // LOGINWINDOWS_H

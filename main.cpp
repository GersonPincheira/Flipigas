#include "loginwindows.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    deque<Solicitud> solicitudes;
    deque<Camion> camiones;
    srand(time(NULL));
    fstream fichero;
    string archivo="/home/pip/seminario/Flipigas/bd.txt";
    string linea;
    string tipo,cerro,mpago,nombre,rut;
    float kilo=0;
    int cantidad,pago;
    Solicitud *re;
    int id=0;
    fichero.open(archivo.c_str(),ios::in);
    if(fichero.is_open()){
        while(!fichero.eof()){
            id++;
            getline(fichero,linea);
            tipo=linea.substr(0,linea.find(';'));
            linea=linea.substr(linea.find(';')+1,linea.size());
            kilo=stoi(linea.substr(0,linea.find(';')));
            linea=linea.substr(linea.find(';')+1,linea.size());
            cantidad=stoi(linea.substr(0,linea.find(';')));
            linea=linea.substr(linea.find(';')+1,linea.size());
            cerro=linea.substr(0,linea.find(';'));
            linea=linea.substr(linea.find(';')+1,linea.size());
            mpago=linea.substr(0,linea.find(';'));
            linea=linea.substr(linea.find(';')+1,linea.size());
            nombre=linea.substr(0,linea.find(';'));
            linea=linea.substr(linea.find(';')+1,linea.size());
            rut=linea.substr(0,linea.find(';'));
            pago=stoi(linea.substr(linea.find(';')+1,linea.size()));
            deque<Cilindro> cilindros;
            for(cantidad;cantidad>0;cantidad--){
                Cilindro n(kilo,tipo);
                cilindros.push_back(n);
            }
            re=new Solicitud(cilindros,cerro,mpago,nombre,rut,0,id,pago);
            solicitudes.push_back(*re);
        }fichero.close();
    }else{
        cout << "no se pudo abrir archivo"<< endl;
    }
    QApplication a(argc, argv);
    LoginWindows w(0,&solicitudes,&camiones);
    w.setWindowTitle("Ingreso");
    w.show();

    return a.exec();
}

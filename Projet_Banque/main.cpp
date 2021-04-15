#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QtCharts>

using namespace QtCharts;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle("Fusion");
    connection c;

    // valeur de i selon si c'est le président (4 || 2) ou le banquier (1)
    int i = c.exec();
    if(i!=0){
    MainWindow w;
    // définie le role de celui qui se connecte ( affecte une variable globale dans la MainWindow )
    w.set_role(i);
    // choisie la vue selon la valeur de i
    w.set_vue();
    w.show();
    return a.exec();
    }

}

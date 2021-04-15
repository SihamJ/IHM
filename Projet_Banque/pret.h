#ifndef PRET_H
#define PRET_H

#include <QWidget>
#include <QtCharts>
#include <QtCharts/QChartView>
#include "mainwindow.h"
#include "principale.h"

namespace Ui {
class pret;
}

class pret : public QWidget
{
    Q_OBJECT

public:
    explicit pret(QWidget *parent = nullptr, int mode = 0);
    ~pret();
    void handle_connections();
    void pret_chart(int i, QString titre);
    void set_up_ui();


public slots:
    void volume();
    void ca();
    void pourcentage();
    void changer_agence();
    void changer_banquier();

private:
    Ui::pret *ui;

};

#endif // PRET_H

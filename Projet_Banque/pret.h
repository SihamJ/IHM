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
    explicit pret(QWidget *parent = nullptr);
    ~pret();
    void handle_connections();
    void pret_chart(int i, QString titre);

public slots:
    void volume();
    void ca();
    void pourcentage();

private:
    Ui::pret *ui;

};

#endif // PRET_H

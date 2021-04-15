#include "pret_banquier.h"
#include "ui_pret_banquier.h"
#include <QtCharts>
#include <QLineSeries>
#include <QChart>
#include <QAreaSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QStringList>
#include <QBarCategoryAxis>
#include <QValueAxis>

pret_banquier::pret_banquier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pret_banquier)
{
    ui->setupUi(this);
    pret(0,"Volume en Euros");
    handle_connections();
}

void pret_banquier::handle_connections()
{
    QObject::connect( ui->vol_pret, &QPushButton::released, this, &pret_banquier::volume );
    QObject::connect( ui->ca_pret, &QPushButton::released, this, &pret_banquier::ca );
    QObject::connect( ui->pourc_pret, &QPushButton::released, this, &pret_banquier::pourcentage );
}


void pret_banquier::ca()
{
    pret(1,"CA");
}

void pret_banquier::volume()
{
    pret(0,"Volume en Euros");
}

void pret_banquier::pourcentage()
{
    pret(2,"Pourcentage");
}

void pret_banquier::pret(int i, const QString titre)
{
    QBarSet *set2 = new QBarSet(titre);

    *set2 << (i+1)*3;

    QBarSeries *series_bours = new QBarSeries();
        series_bours->append(set2);
    QChart *bours = new QChart();
        bours->addSeries(series_bours);
        bours->setTitle("Produit Boursiers");
        bours->setAnimationOptions(QChart::SeriesAnimations);

   QStringList categories_bours;
        categories_bours << "Action";
        QBarCategoryAxis *axisX_bours = new QBarCategoryAxis();
        axisX_bours->append(categories_bours);
        bours->addAxis(axisX_bours, Qt::AlignBottom);
        series_bours->attachAxis(axisX_bours);

   QValueAxis *axisY_bours = new QValueAxis();
        axisY_bours->setRange(0,(i+1)*4);
        bours->addAxis(axisY_bours, Qt::AlignLeft);
        series_bours->attachAxis(axisY_bours);

        bours->legend()->setVisible(true);
        bours->legend()->setAlignment(Qt::AlignBottom);

       ui->chart_pret->setChart(bours);
       ui->chart_pret->setRenderHint(QPainter::Antialiasing);
}

pret_banquier::~pret_banquier()
{
    delete ui;
}

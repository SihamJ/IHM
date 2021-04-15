#include "pret.h"
#include "ui_pret.h"
#include "mainwindow.h"
#include "principale.h"


pret::pret(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pret)
{
    ui->setupUi(this);
    pret_chart(0,"Volume en Euros");

}

void pret::handle_connections()
{
    QObject::connect( ui->vol_pret, &QPushButton::released, this, &pret::volume );
    QObject::connect( ui->ca_pret, &QPushButton::released, this, &pret::ca );
    QObject::connect( ui->pourcentage_pret, &QPushButton::released, this, &pret::pourcentage );
}

void pret::ca()
{
    pret_chart(1,"CA");
}

void pret::volume()
{
    pret_chart(0,"Volume en Euros");
}

void pret::pourcentage()
{
    pret_chart(2,"Pourcentage");
}

void pret::pret_chart(int i, const QString titre)
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


pret::~pret()
{
    delete ui;
}




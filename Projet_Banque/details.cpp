#include "details.h"
#include "ui_details.h"
#include <QtCharts>
#include <QLineSeries>
#include <QChart>
#include <QAreaSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QStringList>
#include <QBarCategoryAxis>
#include <QValueAxis>

int darkmode_d = 0;

details::details(QWidget *parent, int mode):
    QDialog(parent),
    ui(new Ui::details)
{
    darkmode_d = mode;
    ui->setupUi(this);
    set_chart(0,"Volume en Euros");
    handle_connections();
    volume();
}

void details::ca()
{
    set_chart(1,"CA");
}

void details::volume()
{
    set_chart(0,"Volume en Euros");
}

void details::pourcentage()
{
    set_chart(2,"Pourcentage");
}

void details::set_chart(int i, QString titre)
{
    QBarSet *set0 = new QBarSet("Prêts");
    QBarSet *set1 = new QBarSet("Comptes");
    QBarSet *set2 = new QBarSet("Chequiers");
    QBarSet *set3 = new QBarSet("Cartes");

    int range(0);

    // CA
    if(i==1)
        range = 50;
    // Volume ou pourcentage
    else
        range = 100;

    int pret = rand()%range;
    int comptes = rand()%range;
    int chequiers = rand()%range;
    int cartes = rand()%range;

    *set0 << pret;
    *set1 << comptes;
    *set2 << chequiers;
    *set3 << cartes;

    QBarSeries *series_bq = new QBarSeries();
        series_bq->append(set0);
        series_bq->append(set1);
        series_bq->append(set2);
        series_bq->append(set3);

    QChart *bq = new QChart();
        bq->addSeries(series_bq);
        bq->setTitle("Produits Bancaires");
        bq->setAnimationOptions(QChart::SeriesAnimations);

   QStringList categories_bq;
        categories_bq << titre ;
        QBarCategoryAxis *axisX_bq = new QBarCategoryAxis();
        axisX_bq->append(categories_bq);
        bq->addAxis(axisX_bq, Qt::AlignBottom);
        series_bq->attachAxis(axisX_bq);

   QValueAxis *axisY_bq = new QValueAxis();
        axisY_bq->setRange(0,range);
        bq->addAxis(axisY_bq, Qt::AlignLeft);
        series_bq->attachAxis(axisY_bq);

        bq->legend()->setVisible(true);
        bq->legend()->setAlignment(Qt::AlignBottom);
        if(!darkmode_d)
            bq->setBackgroundBrush(QBrush(QColor("transparent")));
       ui->graphe_agrandi->setChart(bq);
       ui->graphe_agrandi->setRenderHint(QPainter::Antialiasing);

       QChart::ChartTheme theme;
       if(darkmode_d)
           theme = static_cast<QChart::ChartTheme>(1);
       else
           theme = static_cast<QChart::ChartTheme>(0);

       ui->graphe_agrandi->chart()->setTheme(theme);
}

void details::handle_connections()
{
    QObject::connect( ui->vol_agrandi, &QPushButton::released, this, &details::volume );
    QObject::connect( ui->ca_agrandi, &QPushButton::released, this, &details::ca );
    QObject::connect( ui->pourcentage_agrandi, &QPushButton::released, this, &details::pourcentage );
}

details::~details()
{
    delete ui;
}

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

details::details(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::details)
{
    ui->setupUi(this);
    set_chart(0,"Volume en Euros");
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
    QBarSet *set1 = new QBarSet(titre);

    *set1 << (i+1)*2 << (i+1)*4;

    QBarSeries *series_assur = new QBarSeries();
        series_assur->append(set1);
    QChart *assur = new QChart();
        assur->addSeries(series_assur);
        assur->setTitle("Produit d'assurance");
        assur->setAnimationOptions(QChart::SeriesAnimations);

   QStringList categories_assur;
        categories_assur << "Vélo" << "Ordi";
        QBarCategoryAxis *axisX_assur = new QBarCategoryAxis();
        axisX_assur->append(categories_assur);
        assur->addAxis(axisX_assur, Qt::AlignBottom);
        series_assur->attachAxis(axisX_assur);

   QValueAxis *axisY_assur = new QValueAxis();
        axisY_assur->setRange(0,(i+1)*5);
        assur->addAxis(axisY_assur, Qt::AlignLeft);
        series_assur->attachAxis(axisY_assur);

        assur->legend()->setVisible(true);
        assur->legend()->setAlignment(Qt::AlignBottom);

       ui->graphe_agrandi->setChart(assur);
       ui->graphe_agrandi->setRenderHint(QPainter::Antialiasing);
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

#include "banquier.h"
#include "ui_banquier.h"
#include <QtCharts>
#include <QLineSeries>
#include <QChart>
#include <QAreaSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QStringList>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include "details.h"

Banquier::Banquier(QWidget *parent, QString name, QString agence) :
    QWidget(parent),

    ui(new Ui::Banquier)
{
    ui->setupUi(this);
    ui->username->setText(name);
    ui->nom_agence->setText(agence);
    set_up_ui();
    handle_connections();
}

void Banquier::details_bq()
{
    details *vue = new details();
    vue->show();
}

void Banquier::details_assur()
{
    details *vue = new details();
    vue->show();
}

void Banquier::details_bours()
{
    details *vue = new details();
    vue->show();
}


void Banquier::set_up_ui()
{
    produit_bancaire(0, "Volume en Euros");
    produit_assur(0, "Volume en Euros");
    produit_bours(0, "Volume en Euros");

}

void Banquier::handle_connections()
{
    QObject::connect( ui->elargir_bq_2, &QPushButton::released, this, &Banquier::details_bq );
    QObject::connect( ui->elargir_assur_2, &QPushButton::released, this, &Banquier::details_assur );
    QObject::connect( ui->elargir_bours_2, &QPushButton::released, this, &Banquier::details_bours );
    QObject::connect( ui->vol_banq_2, &QPushButton::released, this, &Banquier::volume1 );
    QObject::connect( ui->ca_banq_2, &QPushButton::released, this, &Banquier::ca1 );
    QObject::connect( ui->pourc_banq_2, &QPushButton::released, this, &Banquier::pourcentage1 );
    QObject::connect( ui->vol_assur_2, &QPushButton::released, this, &Banquier::volume2 );
    QObject::connect( ui->ca_assur, &QPushButton::released, this, &Banquier::ca2 );
    QObject::connect( ui->pourc_assur, &QPushButton::released, this, &Banquier::pourcentage2 );
    QObject::connect( ui->vol_bours, &QPushButton::released, this, &Banquier::volume3 );
    QObject::connect( ui->ca_bours, &QPushButton::released, this, &Banquier::ca3 );
    QObject::connect( ui->pourc_bours, &QPushButton::released, this, &Banquier::pourcentage3 );
}

void Banquier::ca1()
{
    produit_bancaire(1, "CA");
}

void Banquier::volume1()
{
    produit_bancaire(0, "Volume en Euros");
}

void Banquier::pourcentage1()
{
    produit_bancaire(2, "Pourcentage");
}

void Banquier::ca2()
{
    produit_assur(1, "CA");
}

void Banquier::volume2()
{
    produit_assur(0, "Volume en Euros");
}

void Banquier::pourcentage2()
{
    produit_assur(2, "Pourcentage");
}

void Banquier::ca3()
{
    produit_bours(1, "CA");
}

void Banquier::volume3()
{
    produit_bours(0, "Volume en Euros");
}

void Banquier::pourcentage3()
{
    produit_bours(2, "Pourcentage");
}

void Banquier::produit_bancaire(int i, const QString titre)
{
    QBarSet *set0 = new QBarSet(titre);

    *set0 << (i+1)*2 << i+4 << (i+1)*3 << (i+1)*4;

    QBarSeries *series_bq = new QBarSeries();
        series_bq->append(set0);
    QChart *bq = new QChart();
        bq->addSeries(series_bq);
        bq->setTitle("Produits Banquiers");
        bq->setAnimationOptions(QChart::SeriesAnimations);

   QStringList categories_bq;
        categories_bq << "Prêts" << "Comptes" << "Chéquiers" << "Cartes";
        QBarCategoryAxis *axisX_bq = new QBarCategoryAxis();
        axisX_bq->append(categories_bq);
        bq->addAxis(axisX_bq, Qt::AlignBottom);
        series_bq->attachAxis(axisX_bq);

   QValueAxis *axisY_bq = new QValueAxis();
        axisY_bq->setRange(0,(i+1)*5);
        bq->addAxis(axisY_bq, Qt::AlignLeft);
        series_bq->attachAxis(axisY_bq);

        bq->legend()->setVisible(true);
        bq->legend()->setAlignment(Qt::AlignBottom);

       ui->produit_bq->setChart(bq);
       ui->produit_bq->setRenderHint(QPainter::Antialiasing);
}

void Banquier::produit_assur(int i, const QString titre)
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

       ui->produit_assur->setChart(assur);
       ui->produit_assur->setRenderHint(QPainter::Antialiasing);
}

void Banquier::produit_bours(int i, const QString titre)
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

       ui->produit_bours->setChart(bours);
       ui->produit_bours->setRenderHint(QPainter::Antialiasing);
}

Banquier::~Banquier()
{
    delete ui;
}

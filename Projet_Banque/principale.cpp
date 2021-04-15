#include "principale.h"
#include "ui_principale.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>
#include <QLineSeries>
#include <QChart>
#include <QAreaSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QStringList>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include "pret.h"
#include "banquier.h"
#include "details.h"
#include "connection.h"

int volume = 0;
int ca = 0;
int pourcentage = 0;

principale::principale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::principale)
{
    ui->setupUi(this);
    set_up_ui();
    handle_connections();
}

void principale::set_up_ui()
{
    produit_bancaire(0, "Volume en Euros");
    produit_assur(0, "Volume en Euros");
    produit_bours(0, "Volume en Euros");

}

void principale::handle_connections()
{
    QObject::connect( ui->elargir_bq, &QPushButton::released, this, &principale::details_bq );
    QObject::connect( ui->elargir_assur, &QPushButton::released, this, &principale::details_assur );
    QObject::connect( ui->elargir_bours, &QPushButton::released, this, &principale::details_bours );
    QObject::connect( ui->vol_banq, &QPushButton::released, this, &principale::volume1 );
    QObject::connect( ui->ca_banq, &QPushButton::released, this, &principale::ca1 );
    QObject::connect( ui->pourc_banq, &QPushButton::released, this, &principale::pourcentage1 );
    QObject::connect( ui->vol_assur, &QPushButton::released, this, &principale::volume2 );
    QObject::connect( ui->ca_assur, &QPushButton::released, this, &principale::ca2 );
    QObject::connect( ui->pourc_assur, &QPushButton::released, this, &principale::pourcentage2 );
    QObject::connect( ui->vol_bours, &QPushButton::released, this, &principale::volume3 );
    QObject::connect( ui->ca_bours, &QPushButton::released, this, &principale::ca3 );
    QObject::connect( ui->pourc_bours, &QPushButton::released, this, &principale::pourcentage3 );
    QObject::connect( ui->agence, &QComboBox::currentTextChanged, this, &principale::changer_agence );
    QObject::connect( ui->banquier, &QComboBox::currentTextChanged, this, &principale::changer_banquier );


}

void principale::changer_agence()
{
    QString nom = ui->agence->currentText();
    if (QString::compare(nom,"Toutes Agences") == 0){
        ui->nom_banquier->setText("");
        ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/logo.png'/></p></body></html>");
    }
    if(QString::compare(ui->nom_banquier->text(), "") == 0){
        ui->nom_banquier->setText("");
        ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/logo.png'/></p></body></html>");
    }
    ui->nom_agence->setText(nom);
}

void principale::changer_banquier()
{
    if (QString::compare(ui->agence->currentText(),"Toutes Agences") == 0 || QString::compare(ui->banquier->currentText(),"Tous Banquiers") == 0){
        ui->nom_banquier->setText("");
        ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/logo.png'/></p></body></html>");
    }
    else{
        ui->nom_banquier->setText(ui->banquier->currentText());
        ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/pdp.png'/></p></body></html>");
    }
}

void principale::details_bq()
{

    details *vue = new details();
    vue->show();
}

void principale::details_assur()
{

    details *vue = new details();
    vue->show();
}

void principale::details_bours()
{

    details *vue = new details();
    vue->show();
}

void principale::ca1()
{
    produit_bancaire(1, "CA");
}

void principale::volume1()
{
    produit_bancaire(0, "Volume en Euros");
}

void principale::pourcentage1()
{
    produit_bancaire(2, "Pourcentage");
}

void principale::ca2()
{
    produit_assur(1, "CA");
}

void principale::volume2()
{
    produit_assur(0, "Volume en Euros");
}

void principale::pourcentage2()
{
    produit_assur(2, "Pourcentage");
}

void principale::ca3()
{
    produit_bours(1, "CA");
}

void principale::volume3()
{
    produit_bours(0, "Volume en Euros");
}

void principale::pourcentage3()
{
    produit_bours(2, "Pourcentage");
}

void principale::produit_bancaire(int i, const QString titre)
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

void principale::produit_assur(int i, const QString titre)
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

void principale::produit_bours(int i, const QString titre)
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

principale::~principale()
{
    delete ui;
}

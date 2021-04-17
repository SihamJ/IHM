#include "canal_bancaire.h"
#include "ui_canal_bancaire.h"

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
#include "details.h"
#include "connection.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int darkmode_cb = 0;

int volume_cb = 0;
int ca_cb = 0;
int pourcentage_cb = 0;



canal_bancaire::canal_bancaire(QWidget *parent, int mode) :
    QWidget(parent),
    ui(new Ui::canal_bancaire)
{
    darkmode_cb = mode;
    ui->setupUi(this);
    set_up_ui();
    handle_connections();
}

void canal_bancaire::set_up_ui()
{
    famille_pret(0, "Volume en Euros");
    famille_comptes(0, "Volume en Euros");
    famille_chequier(0, "Volume en Euros");
}

void canal_bancaire::handle_connections()
{
    QObject::connect( ui->elargir_bq, &QPushButton::released, this, &canal_bancaire::details_pret );
    QObject::connect( ui->elargir_assur, &QPushButton::released, this, &canal_bancaire::details_comptes );
    QObject::connect( ui->elargir_bours, &QPushButton::released, this, &canal_bancaire::details_chequier );
    QObject::connect( ui->vol_banq, &QPushButton::released, this, &canal_bancaire::volume1 );
    QObject::connect( ui->ca_banq, &QPushButton::released, this, &canal_bancaire::ca1 );
    QObject::connect( ui->pourc_banq, &QPushButton::released, this, &canal_bancaire::pourcentage1 );
    QObject::connect( ui->vol_assur, &QPushButton::released, this, &canal_bancaire::volume2 );
    QObject::connect( ui->ca_assur, &QPushButton::released, this, &canal_bancaire::ca2 );
    QObject::connect( ui->pourc_assur, &QPushButton::released, this, &canal_bancaire::pourcentage2 );
    QObject::connect( ui->vol_bours, &QPushButton::released, this, &canal_bancaire::volume3 );
    QObject::connect( ui->ca_bours, &QPushButton::released, this, &canal_bancaire::ca3 );
    QObject::connect( ui->pourc_bours, &QPushButton::released, this, &canal_bancaire::pourcentage3 );
    QObject::connect( ui->agence, &QComboBox::currentTextChanged, this, &canal_bancaire::changer_agence );
    QObject::connect( ui->banquier, &QComboBox::currentTextChanged, this, &canal_bancaire::changer_banquier );
    QObject::connect( ui->duree, &QComboBox::currentTextChanged, this, &canal_bancaire::set_up_ui );
    QObject::connect( ui->date, &QDateEdit::dateChanged, this, &canal_bancaire::set_up_ui );


}

void canal_bancaire::changer_agence()
{
    ui->nom_banquier->setText("");
    ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/logo.png'/></p></body></html>");
    set_up_ui();
    ui->nom_agence->setText(ui->agence->currentText());
}

void canal_bancaire::changer_banquier()
{
    if (QString::compare(ui->agence->currentText(),"Toutes Agences") == 0 || QString::compare(ui->banquier->currentText(),"Tous Banquiers") == 0){
        ui->nom_banquier->setText("");
        ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/logo.png'/></p></body></html>");
    }
    else{
        ui->nom_banquier->setText(ui->banquier->currentText());
        ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/pdp.png'/></p></body></html>");
        set_up_ui();
    }
}

void canal_bancaire::details_pret()
{

    details *vue = new details();
    vue->show();
}

void canal_bancaire::details_comptes()
{

    details *vue = new details();
    vue->show();
}

void canal_bancaire::details_chequier()
{

    details *vue = new details();
    vue->show();
}

void canal_bancaire::ca1()
{
    famille_pret(1, "CA");
}

void canal_bancaire::volume1()
{
    famille_pret(0, "Volume en Euros");
}

void canal_bancaire::pourcentage1()
{
    famille_pret(2, "Pourcentage");
}

void canal_bancaire::ca2()
{
    famille_comptes(1, "CA");
}

void canal_bancaire::volume2()
{
    famille_comptes(0, "Volume en Euros");
}

void canal_bancaire::pourcentage2()
{
    famille_comptes(2, "Pourcentage");
}

void canal_bancaire::ca3()
{
    famille_chequier(1, "CA");
}

void canal_bancaire::volume3()
{
    famille_chequier(0, "Volume en Euros");
}

void canal_bancaire::pourcentage3()
{
    famille_chequier(2, "Pourcentage");
}

void canal_bancaire::famille_pret(int i, const QString titre)
{
    int range(0);
    // CA
    if(i==1)
        range = 50;
    // Volume ou pourcentage
    else
        range = 100;

    if(QString::compare(ui->duree->currentText(),"1 Journée")==0){
        QBarSet *set0 = new QBarSet("Habitations");
        QBarSet *set1 = new QBarSet("Auto");

        int pret_hab = rand()%range;
        int pret_auto = rand()%range;

        *set0 << pret_hab;
        *set1 << pret_auto;

        QBarSeries *series_bq = new QBarSeries();
            series_bq->append(set0);
            series_bq->append(set1);

        QChart *bq = new QChart();
            bq->addSeries(series_bq);
            bq->setTitle("Prêts");
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
            if(!darkmode_cb)
                bq->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->produit_bq->setChart(bq);
           ui->produit_bq->setRenderHint(QPainter::Antialiasing);
    }

    else{

        QLineSeries *pret_hab = new QLineSeries();
        pret_hab->append(0, rand()%range);
            pret_hab->append(1, rand()%range);
            pret_hab->append(2, rand()%range);
            pret_hab->append(3, rand()%range);
            pret_hab->append(4, rand()%range);
            pret_hab->append(5, rand()%range);
            pret_hab->append(6, rand()%range);
            pret_hab->append(7, rand()%range);
        pret_hab->setName("Habitations");

        QLineSeries *pret_auto = new QLineSeries();
        pret_auto->append(0, rand()%range);
            pret_auto->append(1, rand()%range);
            pret_auto->append(2, rand()%range);
            pret_auto->append(3, rand()%range);
            pret_auto->append(4, rand()%range);
            pret_auto->append(5, rand()%range);
            pret_auto->append(6, rand()%range);
            pret_auto->append(7, rand()%range);
        pret_auto->setName("Auto");

        QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(pret_hab);
            chart->addSeries(pret_auto);

            chart->createDefaultAxes();
            chart->setTitle(titre);
            if(!darkmode_cb)
                chart->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->produit_bq->setChart(chart);
         ui->produit_bq->setRenderHint(QPainter::Antialiasing);
        }
    QChart::ChartTheme theme;
    if(darkmode_cb)
        theme = static_cast<QChart::ChartTheme>(1);
    else
        theme = static_cast<QChart::ChartTheme>(0);

    ui->produit_bq->chart()->setTheme(theme);
}

void canal_bancaire::famille_comptes(int i, const QString titre)
{
    int range(0);

    if(i==1)
        range = 50;
    else
        range = 100;

    if(QString::compare(ui->duree->currentText(),"1 Journée")==0){
        QBarSet *set0 = new QBarSet("Courant");
        QBarSet *set1 = new QBarSet("Epargne");


        int courant = rand()%range;
        int epargne = rand()%range;

        *set0 << courant;
        *set1 << epargne;

        QBarSeries *series_assur = new QBarSeries();
            series_assur->append(set0);
            series_assur->append(set1);
        QChart *assur = new QChart();
            assur->addSeries(series_assur);
            assur->setTitle("Comptes");
            assur->setAnimationOptions(QChart::SeriesAnimations);

       QStringList categories_assur;
            categories_assur << titre;
            QBarCategoryAxis *axisX_assur = new QBarCategoryAxis();
            axisX_assur->append(categories_assur);
            assur->addAxis(axisX_assur, Qt::AlignBottom);
            series_assur->attachAxis(axisX_assur);

       QValueAxis *axisY_assur = new QValueAxis();
            axisY_assur->setRange(0,range);
            assur->addAxis(axisY_assur, Qt::AlignLeft);
            series_assur->attachAxis(axisY_assur);

            assur->legend()->setVisible(true);
            assur->legend()->setAlignment(Qt::AlignBottom);
            if(!darkmode_cb)
                assur->setBackgroundBrush(QBrush(QColor("transparent")));
           ui->produit_assur->setChart(assur);
           ui->produit_assur->setRenderHint(QPainter::Antialiasing);
    }
    else{
        QLineSeries *courant = new QLineSeries();
        courant->append(0, rand()%range);
            courant->append(1, rand()%range);
            courant->append(2, rand()%range);
            courant->append(3, rand()%range);
            courant->append(4, rand()%range);
            courant->append(5, rand()%range);
            courant->append(6, rand()%range);
            courant->append(7, rand()%range);
        courant->setName("Ordi");

        QLineSeries *epargne = new QLineSeries();
        epargne->append(0, rand()%range);
            epargne->append(1, rand()%range);
            epargne->append(2, rand()%range);
            epargne->append(3, rand()%range);
            epargne->append(4, rand()%range);
            epargne->append(5, rand()%range);
            epargne->append(6, rand()%range);
            epargne->append(7, rand()%range);
        epargne->setName("Epargne");


        QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(courant);
            chart->addSeries(epargne);
            chart->createDefaultAxes();
            chart->setTitle(titre);
            if(!darkmode_cb)
                chart->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->produit_assur->setChart(chart);
            ui->produit_assur->setRenderHint(QPainter::Antialiasing);
        }
    QChart::ChartTheme theme;
    if(darkmode_cb)
        theme = static_cast<QChart::ChartTheme>(1);

    else
        theme = static_cast<QChart::ChartTheme>(0);

    ui->produit_assur->chart()->setTheme(theme);
}

void canal_bancaire::famille_chequier(int i, const QString titre)
{
    int range(0);
    // CA
    if(i==1)
        range = 50;
    // Volume ou pourcentage
    else
        range = 100;

    if(QString::compare(ui->duree->currentText(),"1 Journée")==0){
    QBarSet *set2 = new QBarSet("Action");


    int action = rand()%range;

    *set2 << action;

    QBarSeries *series_bours = new QBarSeries();
        series_bours->append(set2);
    QChart *bours = new QChart();
        bours->addSeries(series_bours);
        bours->setTitle("Chéquiers");
        bours->setAnimationOptions(QChart::SeriesAnimations);

   QStringList categories_bours;
        categories_bours << titre;
        QBarCategoryAxis *axisX_bours = new QBarCategoryAxis();
        axisX_bours->append(categories_bours);
        bours->addAxis(axisX_bours, Qt::AlignBottom);
        series_bours->attachAxis(axisX_bours);

   QValueAxis *axisY_bours = new QValueAxis();
        axisY_bours->setRange(0,range);
        bours->addAxis(axisY_bours, Qt::AlignLeft);
        series_bours->attachAxis(axisY_bours);

        bours->legend()->setVisible(true);
        bours->legend()->setAlignment(Qt::AlignBottom);
        if(!darkmode_cb)
            bours->setBackgroundBrush(QBrush(QColor("transparent")));
       ui->produit_bours->setChart(bours);
       ui->produit_bours->setRenderHint(QPainter::Antialiasing);
    }
    else{
        QLineSeries *ordi = new QLineSeries();
        ordi->append(0, rand()%range);
            ordi->append(1, rand()%range);
            ordi->append(2, rand()%range);
            ordi->append(3, rand()%range);
            ordi->append(4, rand()%range);
            ordi->append(5, rand()%range);
            ordi->append(6, rand()%range);
            ordi->append(7, rand()%range);
        ordi->setName("Ordi");


        QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(ordi);
            chart->createDefaultAxes();
            chart->setTitle("Chéquiers");
            if(!darkmode_cb)
                chart->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->produit_bours->setChart(chart);
            ui->produit_bours->setRenderHint(QPainter::Antialiasing);
    }
    QChart::ChartTheme theme;
    if(darkmode_cb)
        theme = static_cast<QChart::ChartTheme>(1);
    else
        theme = static_cast<QChart::ChartTheme>(0);

    ui->produit_bours->chart()->setTheme(theme);
    QPalette pal = window()->palette();
}

canal_bancaire::~canal_bancaire()
{
    delete ui;
}

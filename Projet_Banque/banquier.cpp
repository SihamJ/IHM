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

int darkmode_b = 0;

Banquier::Banquier(QWidget *parent, QString name, QString agence, int mode) :
    QWidget(parent),

    ui(new Ui::Banquier)
{
    darkmode_b = mode;
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
    QObject::connect( ui->elargir_bq, &QPushButton::released, this, &Banquier::details_bq );
    QObject::connect( ui->elargir_assur, &QPushButton::released, this, &Banquier::details_assur );
    QObject::connect( ui->elargir_bours, &QPushButton::released, this, &Banquier::details_bours );
    QObject::connect( ui->vol_banq, &QPushButton::released, this, &Banquier::volume1 );
    QObject::connect( ui->ca_banq, &QPushButton::released, this, &Banquier::ca1 );
    QObject::connect( ui->pourc_banq, &QPushButton::released, this, &Banquier::pourcentage1 );
    QObject::connect( ui->vol_assur, &QPushButton::released, this, &Banquier::volume2 );
    QObject::connect( ui->ca_assur, &QPushButton::released, this, &Banquier::ca2 );
    QObject::connect( ui->pourc_assur, &QPushButton::released, this, &Banquier::pourcentage2 );
    QObject::connect( ui->vol_bours, &QPushButton::released, this, &Banquier::volume3 );
    QObject::connect( ui->ca_bours, &QPushButton::released, this, &Banquier::ca3 );
    QObject::connect( ui->pourc_bours, &QPushButton::released, this, &Banquier::pourcentage3 );
    QObject::connect( ui->duree, &QComboBox::currentTextChanged, this, &Banquier::set_up_ui );
    QObject::connect( ui->date, &QDateEdit::dateChanged, this, &Banquier::set_up_ui );

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

// i=0: Volume ; i=1: CA ; i=2: Pourcentage
void Banquier::produit_bancaire(int i, const QString titre)
{
    int range(0);
    // CA
    if(i==1)
        range = 50;
    // Volume ou pourcentage
    else
        range = 100;

    if(QString::compare(ui->duree->currentText(),"1 Journée")==0){
        QBarSet *set0 = new QBarSet("Prêts");
        QBarSet *set1 = new QBarSet("Comptes");
        QBarSet *set2 = new QBarSet("Chequiers");
        QBarSet *set3 = new QBarSet("Cartes");

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
            bq->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->produit_bq->setChart(bq);
           ui->produit_bq->setRenderHint(QPainter::Antialiasing);
    }

    else{

        QLineSeries *pret = new QLineSeries();
        pret->append(0, rand()%range);
            pret->append(1, rand()%range);
            pret->append(2, rand()%range);
            pret->append(3, rand()%range);
            pret->append(4, rand()%range);
            pret->append(5, rand()%range);
            pret->append(6, rand()%range);
            pret->append(7, rand()%range);
        pret->setName("Prêts");

        QLineSeries *comptes = new QLineSeries();
        comptes->append(0, rand()%range);
            comptes->append(1, rand()%range);
            comptes->append(2, rand()%range);
            comptes->append(3, rand()%range);
            comptes->append(4, rand()%range);
            comptes->append(5, rand()%range);
            comptes->append(6, rand()%range);
            comptes->append(7, rand()%range);
        comptes->setName("Comptes");

        QLineSeries *chequiers = new QLineSeries();
        chequiers->append(0, rand()%range);
            chequiers->append(1, rand()%range);
            chequiers->append(2, rand()%range);
            chequiers->append(3, rand()%range);
            chequiers->append(4, rand()%range);
            chequiers->append(5, rand()%range);
            chequiers->append(6, rand()%range);
            chequiers->append(7, rand()%range);
         chequiers->setName("Chequiers");

        QLineSeries *cartes = new QLineSeries();
        cartes->append(0, rand()%range);
            cartes->append(1, rand()%range);
            cartes->append(2, rand()%range);
            cartes->append(3, rand()%range);
            cartes->append(4, rand()%range);
            cartes->append(5, rand()%range);
            cartes->append(6, rand()%range);
            cartes->append(7, rand()%range);
         cartes->setName("Cartes");
        cartes->setObjectName("Cartes");
        //*cartes << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
        QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(pret);
            chart->addSeries(comptes);
            chart->addSeries(chequiers);
            chart->addSeries(cartes);
            chart->createDefaultAxes();
            chart->setTitle(titre);
            if(!darkmode_b)
                chart->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->produit_bq->setChart(chart);
         ui->produit_bq->setRenderHint(QPainter::Antialiasing);
        }
    QChart::ChartTheme theme;
    if(darkmode_b)
        theme = static_cast<QChart::ChartTheme>(1);
    else
        theme = static_cast<QChart::ChartTheme>(0);

    ui->produit_bq->chart()->setTheme(theme);
    QPalette pal = window()->palette();
}

void Banquier::produit_assur(int i, const QString titre)
{
    int range(0);

    if(i==1)
        range = 50;
    else
        range = 100;

    if(QString::compare(ui->duree->currentText(),"1 Journée")==0){
        QBarSet *set0 = new QBarSet("Ordi");
        QBarSet *set1 = new QBarSet("Vélo");


        int ordi = rand()%range;
        int velo = rand()%range;

        *set0 << ordi;
        *set1 << velo;

        QBarSeries *series_assur = new QBarSeries();
            series_assur->append(set0);
            series_assur->append(set1);
        QChart *assur = new QChart();
            assur->addSeries(series_assur);
            assur->setTitle("Produit d'assurance");
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
            if(!darkmode_b)
                assur->setBackgroundBrush(QBrush(QColor("transparent")));
           ui->produit_assur->setChart(assur);
           ui->produit_assur->setRenderHint(QPainter::Antialiasing);
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

        QLineSeries *velo = new QLineSeries();
        velo->append(0, rand()%range);
            velo->append(1, rand()%range);
            velo->append(2, rand()%range);
            velo->append(3, rand()%range);
            velo->append(4, rand()%range);
            velo->append(5, rand()%range);
            velo->append(6, rand()%range);
            velo->append(7, rand()%range);
        velo->setName("Vélo");


        QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(ordi);
            chart->addSeries(velo);
            chart->createDefaultAxes();
            chart->setTitle(titre);
            if(!darkmode_b)
                chart->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->produit_bq->setChart(chart);
            ui->produit_bq->setRenderHint(QPainter::Antialiasing);
        }
    QChart::ChartTheme theme;
    if(darkmode_b)
        theme = static_cast<QChart::ChartTheme>(1);

    else
        theme = static_cast<QChart::ChartTheme>(0);

    ui->produit_bq->chart()->setTheme(theme);
}

void Banquier::produit_bours(int i, const QString titre)
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
        bours->setTitle("Produit Boursiers");
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
        if(!darkmode_b)
            bours->setBackgroundBrush(QBrush(QColor("transparent")));
        bours->setTitleBrush(QBrush(QColor("white")));
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
            chart->setTitle(titre);
            if(!darkmode_b)
                chart->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->produit_bq->setChart(chart);
            ui->produit_bq->setRenderHint(QPainter::Antialiasing);
    }
    QChart::ChartTheme theme;
    if(darkmode_b)
        theme = static_cast<QChart::ChartTheme>(1);
    else
        theme = static_cast<QChart::ChartTheme>(0);

    ui->produit_bq->chart()->setTheme(theme);
    QPalette pal = window()->palette();
}

Banquier::~Banquier()
{
    delete ui;
}

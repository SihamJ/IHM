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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);

     QBarSet *set0 = new QBarSet("Volume en Euro");

     *set0 << 3 << 8 << 6 << 9;

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
         axisY_bq->setRange(0,11);
         bq->addAxis(axisY_bq, Qt::AlignLeft);
         series_bq->attachAxis(axisY_bq);

         bq->legend()->setVisible(true);
         bq->legend()->setAlignment(Qt::AlignBottom);

        ui->produit_bq->setChart(bq);
        ui->produit_bq->setRenderHint(QPainter::Antialiasing);


        QBarSet *set1 = new QBarSet("Volume en Euro");

        *set1 << 3 << 8;

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
            axisY_assur->setRange(0,11);
            assur->addAxis(axisY_assur, Qt::AlignLeft);
            series_assur->attachAxis(axisY_assur);

            assur->legend()->setVisible(true);
            assur->legend()->setAlignment(Qt::AlignBottom);

           ui->produit_assur->setChart(assur);
           ui->produit_assur->setRenderHint(QPainter::Antialiasing);

           QBarSet *set2 = new QBarSet("Volume en Euro");

           *set2 << 7;

           QBarSeries *series_bours = new QBarSeries();
               series_bours->append(set2);
           QChart *bours = new QChart();
               bours->addSeries(series_bours);
               bours->setTitle("Produit Boursiers");
               bours->setAnimationOptions(QChart::SeriesAnimations);

          QStringList categories_bours;
               categories_assur << "Action";
               QBarCategoryAxis *axisX_bours = new QBarCategoryAxis();
               axisX_bours->append(categories_bours);
               assur->addAxis(axisX_bours, Qt::AlignBottom);
               series_bours->attachAxis(axisX_bours);

          QValueAxis *axisY_bours = new QValueAxis();
               axisY_bours->setRange(0,11);
               assur->addAxis(axisY_bours, Qt::AlignLeft);
               series_bours->attachAxis(axisY_bours);

               bours->legend()->setVisible(true);
               bours->legend()->setAlignment(Qt::AlignBottom);

              ui->produit_bours->setChart(bours);
              ui->produit_bours->setRenderHint(QPainter::Antialiasing);
}


void MainWindow::handle_connections()
{
    QObject::connect(ui->vol_banq, SIGNAL(clicked), this, SLOT(quit));
}

MainWindow::~MainWindow()
{
    delete ui;
}


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

int darkmode_pb = 0;

pret_banquier::pret_banquier(QWidget *parent, int mode) :
    QWidget(parent),
    ui(new Ui::pret_banquier)
{
    darkmode_pb = mode;
    ui->setupUi(this);
    set_up_ui();
    handle_connections();
}

void pret_banquier::handle_connections()
{
    QObject::connect( ui->vol_pret, &QPushButton::released, this, &pret_banquier::volume );
    QObject::connect( ui->ca_pret, &QPushButton::released, this, &pret_banquier::ca );
    QObject::connect( ui->pourc_pret, &QPushButton::released, this, &pret_banquier::pourcentage );
    QObject::connect( ui->duree, &QComboBox::currentTextChanged, this, &pret_banquier::set_up_ui );
    QObject::connect( ui->date, &QDateEdit::dateChanged, this, &pret_banquier::set_up_ui );

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

void pret_banquier::set_up_ui(){
    pret(0,"Volume en Euro");
}

void pret_banquier::pret(int i, const QString titre)
{
    int range(0);
    if(i==1)
        range = 50;
    else
        range = 100;

    if(QString::compare(ui->duree->currentText(),"1 Journée")==0){
        QBarSet *set0 = new QBarSet("Habitation");
        QBarSet *set1 = new QBarSet("Auto");


        int pret_habitation = rand()%range;
        int pret_auto = rand()%range;

        *set0 << pret_habitation;
        *set1 << pret_auto;

        QBarSeries *series_pret = new QBarSeries();
            series_pret->append(set0);
            series_pret->append(set1);
            QChart *bours = new QChart();
            bours->addSeries(series_pret);
            bours->setTitle("Famille Prêts");
            bours->setAnimationOptions(QChart::SeriesAnimations);

       QStringList categories_pret;
            categories_pret << titre;
            QBarCategoryAxis *axisX_bours = new QBarCategoryAxis();
            axisX_bours->append(categories_pret);
            bours->addAxis(axisX_bours, Qt::AlignBottom);
            series_pret->attachAxis(axisX_bours);

       QValueAxis *axisY_bours = new QValueAxis();
            axisY_bours->setRange(0,range);
            bours->addAxis(axisY_bours, Qt::AlignLeft);
            series_pret->attachAxis(axisY_bours);

            bours->legend()->setVisible(true);
            bours->legend()->setAlignment(Qt::AlignBottom);
            if(!darkmode_pb)
                bours->setBackgroundBrush(QBrush(QColor("transparent")));
           ui->chart_pret->setChart(bours);
           ui->chart_pret->setRenderHint(QPainter::Antialiasing);
    }
    else{
        QLineSeries *habitation = new QLineSeries();
        habitation->append(0, rand()%range);
            habitation->append(1, rand()%range);
            habitation->append(2, rand()%range);
            habitation->append(3, rand()%range);
            habitation->append(4, rand()%range);
            habitation->append(5, rand()%range);
            habitation->append(6, rand()%range);
            habitation->append(7, rand()%range);
        habitation->setName("Habitation");

        QLineSeries *autop = new QLineSeries();
        autop->append(0, rand()%range);
            autop->append(1, rand()%range);
            autop->append(2, rand()%range);
            autop->append(3, rand()%range);
            autop->append(4, rand()%range);
            autop->append(5, rand()%range);
            autop->append(6, rand()%range);
            autop->append(7, rand()%range);
        autop->setName("Auto");


        QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(habitation);
            chart->addSeries(autop);
            chart->createDefaultAxes();
            chart->setTitle(titre);
            if(!darkmode_pb)
                chart->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->chart_pret->setChart(chart);
            ui->chart_pret->setRenderHint(QPainter::Antialiasing);
    }
    QChart::ChartTheme theme;
    if(darkmode_pb)
        theme = static_cast<QChart::ChartTheme>(1);
    else
        theme = static_cast<QChart::ChartTheme>(0);

    ui->chart_pret->chart()->setTheme(theme);
    QPalette pal = window()->palette();
}

pret_banquier::~pret_banquier()
{
    delete ui;
}

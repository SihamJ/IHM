#include "pret.h"
#include "ui_pret.h"
#include "mainwindow.h"
#include "principale.h"

int darkmode_p = 0;

pret::pret(QWidget *parent, int mode) :
    QWidget(parent),
    ui(new Ui::pret)
{
    darkmode_p = mode;
    ui->setupUi(this);
    set_up_ui();
    handle_connections();
}

void pret::handle_connections()
{
    QObject::connect( ui->vol_pret, &QPushButton::released, this, &pret::volume );
    QObject::connect( ui->ca_pret, &QPushButton::released, this, &pret::ca );
    QObject::connect( ui->pourcentage_pret, &QPushButton::released, this, &pret::pourcentage );
    QObject::connect( ui->agence, &QComboBox::currentTextChanged, this, &pret::changer_agence );
    QObject::connect( ui->banquier, &QComboBox::currentTextChanged, this, &pret::changer_banquier );
    QObject::connect( ui->duree, &QComboBox::currentTextChanged, this, &pret::set_up_ui );
    QObject::connect( ui->date, &QDateEdit::dateChanged, this, &pret::set_up_ui );

}

void pret::set_up_ui()
{
   pret_chart(0,"Volume en Euros");
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
    int range(0);
    if(i==1)
        range = 50;
    else
        range = 100;
    QComboBox* duree = ui->duree;

    if(QString::compare(duree->currentText(),"1 Journée")==0){
        QBarSet *set0 = new QBarSet("Habitation");
        QBarSet *set1 = new QBarSet("Auto");

        int range(0);
        if(i==1)
            range = 50;
        else
            range = 100;
        int pret_habitation = rand()%range;
        int pret_auto = rand()%range;

        *set0 << pret_habitation;
        *set1 << pret_auto;

        QBarSeries *series_pret = new QBarSeries();
            series_pret->append(set0);
            series_pret->append(set1);
            QChart *pret = new QChart();
            pret->addSeries(series_pret);
            pret->setTitle("Famille Prêts");
            pret->setAnimationOptions(QChart::SeriesAnimations);

       QStringList categories_pret;
            categories_pret << titre;
            QBarCategoryAxis *axisX_bours = new QBarCategoryAxis();
            axisX_bours->append(categories_pret);
            pret->addAxis(axisX_bours, Qt::AlignBottom);
            series_pret->attachAxis(axisX_bours);

       QValueAxis *axisY_bours = new QValueAxis();
            axisY_bours->setRange(0,range);
            pret->addAxis(axisY_bours, Qt::AlignLeft);
            series_pret->attachAxis(axisY_bours);

            pret->legend()->setVisible(true);
            pret->legend()->setAlignment(Qt::AlignBottom);
            if(!darkmode_p)
                pret->setBackgroundBrush(QBrush(QColor("transparent")));
           ui->chart_pret->setChart(pret);
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
            if(!darkmode_p)
                chart->setBackgroundBrush(QBrush(QColor("transparent")));
            ui->chart_pret->setChart(chart);
            ui->chart_pret->setRenderHint(QPainter::Antialiasing);
    }
    QChart::ChartTheme theme;
    if(darkmode_p)
        theme = static_cast<QChart::ChartTheme>(1);
    else
        theme = static_cast<QChart::ChartTheme>(0);

    ui->chart_pret->chart()->setTheme(theme);
}

void pret::changer_agence()
{
    ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/logo.png'/></p></body></html>");
    ui->nom_agence->setText(ui->agence->currentText());
    ui->nom_banquier->setText("");

    // Mise à jour graphe
    pret_chart(0, "Volume Bancaire");
}

void pret::changer_banquier()
{
    if (QString::compare(ui->agence->currentText(),"Toutes Agences") == 0){
        ui->nom_banquier->setText("");
        ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/logo.png'/></p></body></html>");
    }
    else if( QString::compare(ui->banquier->currentText(),"Tous") == 0){
        ui->nom_banquier->setText("");
        ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/logo.png'/></p></body></html>");
        pret_chart(0, "Volume Bancaire");
    }
    else{
        ui->nom_banquier->setText(ui->banquier->currentText());
        ui->image->setText("<html><head/><body><p align='center'><img src=':/assets/pdp.png'/></p></body></html>");
        pret_chart(0, "Volume Bancaire");
    }
}

pret::~pret()
{
    delete ui;
}




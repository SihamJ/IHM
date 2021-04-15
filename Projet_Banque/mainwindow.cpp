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
#include <QIcon>
#include <QPalette>
#include <QColor>
#include "pret.h"
#include "pret_banquier.h"
#include "banquier.h"
#include "details.h"
#include "connection.h"
#include "principale.h"
#include "guide.h"

int mode = 1;
int president = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     color_mode();
     toolbar();
}

void MainWindow::set_role(int i)
{
    if (i==2 || i==4)
        president = 1;
    else
        president = 0;
}

void MainWindow::set_vue()
{
    if (president == 1)
        this->vue_principale();
    else
        this->vue_banquier();
}

void MainWindow::vue_principale()
{
    principale* vue = new principale(this);
    setCentralWidget(vue);
}

void MainWindow::vue_banquier()
{
    Banquier* vue = new Banquier(this);
    setCentralWidget(vue);
}

void MainWindow::guide()
{
    Guide* vue = new Guide(this);
    vue->show();
}

void MainWindow::vue_pret()
{
    if(president == 1)
    {
        pret* vue = new pret(this);
        setCentralWidget( vue );
    }
    else{
        pret_banquier* vue = new pret_banquier(this);
        setCentralWidget( vue );
    }
}

void MainWindow::toolbar()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *extraire_pdf = new QAction("&Extraire PDF", this);
    extraire_pdf->setIcon(QIcon("quitter.png"));
    menuFichier->addAction(extraire_pdf);

    QAction *deconnexion = new QAction("&Deconnexion", this);
    deconnexion->setIcon(QIcon("quitter.png"));
    menuFichier->addAction(deconnexion);

    QAction *actionQuitter = new QAction("&Quitter", this);
    actionQuitter->setIcon(QIcon("quitter.png"));
    menuFichier->addAction(actionQuitter);

    QMenu *menuAffichage = menuBar()->addMenu("&Vue");
    QAction *dark_mode = new QAction("&Dark Mode", this);
    actionQuitter->setIcon(QIcon("quitter.png"));
    menuAffichage->addAction(dark_mode);

    QMenu *menuAide = menuBar()->addMenu("&Aide");
    QAction *guide = new QAction("&Guide", this);
    guide->setIcon(QIcon("quitter.png"));
    menuAide->addAction(guide);

    QToolBar *toolBarVues = addToolBar("Vue");
    QAction *vue_pr = new QAction("&vue principale", this);
    toolBarVues->addAction(vue_pr);

    QAction *vue_pret = new QAction("&Famille Prêts", this);
    toolBarVues->addAction(vue_pret);

  //  QObject::connect( deconnexion, &QAction::triggered, this, &MainWindow::connection );
    QObject::connect( actionQuitter, &QAction::triggered, this, &QApplication::quit );
    QObject::connect( vue_pret, &QAction::triggered, this, &MainWindow::vue_pret );
    QObject::connect( vue_pr, &QAction::triggered, this, &MainWindow::set_vue );
    QObject::connect( dark_mode, &QAction::triggered, this, &MainWindow::color_mode );
    QObject::connect( guide, &QAction::triggered, this, &MainWindow::guide );

}

void MainWindow::color_mode()
{


    QPalette palette;
        if(mode == 0){
            palette.setColor(QPalette::Window, QColor(53, 53, 53));
            palette.setColor(QPalette::WindowText, QColor(255, 255, 255));
            palette.setColor(QPalette::Text, Qt::white);
            palette.setColor(QPalette::ToolTipText, Qt::white);
            palette.setColor(QPalette::ButtonText, Qt::white);
            palette.setColor(QPalette::HighlightedText, Qt::white);
            palette.setColor(QPalette::BrightText, Qt::white);
            palette.setColor(QPalette::Base, QColor(25, 25, 25));
            palette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
            palette.setColor(QPalette::ToolTipBase, Qt::black);
            palette.setColor(QPalette::Button, QColor(53, 53, 53));
            palette.setColor(QPalette::Link, QColor(42, 130, 218));
            palette.setColor(QPalette::Highlight, QColor(42, 130, 218));
        }
        else{
            palette.setColor(QPalette::Window, QColor(250, 250, 255));
            palette.setColor(QPalette::WindowText, Qt::black);
            palette.setColor(QPalette::Text, Qt::black);
            palette.setColor(QPalette::Base, QColor(236, 236, 236));
            palette.setColor(QPalette::AlternateBase, QColor(203, 203, 203));
            palette.setColor(QPalette::ToolTipBase, Qt::white);
            palette.setColor(QPalette::ToolTipText, Qt::black);
            palette.setColor(QPalette::Text, Qt::black);
            palette.setColor(QPalette::Button, QColor(125, 195, 225));
            palette.setColor(QPalette::ButtonText, Qt::black);
            palette.setColor(QPalette::BrightText, Qt::red);
            palette.setColor(QPalette::Link, QColor(42, 130, 218));
            palette.setColor(QPalette::Highlight, QColor(104, 126, 40));
            palette.setColor(QPalette::HighlightedText, Qt::white);
        }
    mode = (mode + 1) % 2;
    QApplication::setPalette(palette);
    this->setPalette(palette);
    this->set_vue();
}

MainWindow::~MainWindow()
{
    delete ui;
}


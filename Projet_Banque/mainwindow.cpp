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
    if (i==2 || i==5)
        president = 1;
    else
        president = 0;
}

void MainWindow::set_vue()
{
    if (president == 1)
        this->vue_principale(mode);
    else
        this->vue_banquier(mode);
}

void MainWindow::vue_principale(int mode)
{
    principale* vue = new principale(this, mode);
    setCentralWidget(vue);
}

void MainWindow::vue_banquier(int mode)
{
    Banquier* vue = new Banquier(this, "Yannis Moujab", "Mulhouse", mode);
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
        pret* vue = new pret(this, mode);
        setCentralWidget( vue );
    }
    else{
        pret_banquier* vue = new pret_banquier(this, mode);
        setCentralWidget( vue );
    }
}

void MainWindow::toolbar()
{
    // Menu
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *extraire_pdf = new QAction("&Extraire PDF", this);
    menuFichier->addAction(extraire_pdf);
    QAction *deconnexion = new QAction("&Deconnexion", this);
    menuFichier->addAction(deconnexion);
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);

    QMenu *menuAffichage = menuBar()->addMenu("&Vue");
    QAction *dark_mode = new QAction("&Dark Mode", this);
    dark_mode->setIcon(QIcon(":/assets/darkmode.png"));
    menuAffichage->addAction(dark_mode);

    QMenu *menuAide = menuBar()->addMenu("&Aide");
    QAction *guide = new QAction("&Guide", this);
    menuAide->addAction(guide);


    // ToolBar avec des icônes
    QToolBar *toolBarVues = addToolBar("Vue");
    QAction *vue_pr = toolBarVues->addAction(QIcon(":/assets/principale.png"),"&Vue Principale");
    QAction *vue_pret = toolBarVues->addAction(QIcon(":/assets/pret.png"),"&Famille Prêt");
    QAction *darkmode = toolBarVues->addAction(QIcon(":/assets/darkmode.png"),"&Dark Mode");

    toolBarVues->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QObject::connect( deconnexion, &QAction::triggered, this, &MainWindow::connection );
    QObject::connect( actionQuitter, &QAction::triggered, this, &QApplication::quit );
    QObject::connect( vue_pret, &QAction::triggered, this, &MainWindow::vue_pret );
    QObject::connect( vue_pr, &QAction::triggered, this, &MainWindow::set_vue );
    QObject::connect( dark_mode, &QAction::triggered, this, &MainWindow::color_mode );
    QObject::connect( guide, &QAction::triggered, this, &MainWindow::guide );
    QObject::connect( darkmode, &QAction::triggered, this, &MainWindow::color_mode );
}

void MainWindow::connection(){
    class connection c;
    c.show();
}

void MainWindow::color_mode()
{


    QPalette palette;
        if(mode == 0){
            palette.setColor(QPalette::Window, QColor(63, 63, 63));
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
            palette.setColor(QPalette::Button, QColor(105, 175, 195));
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


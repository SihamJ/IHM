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
#include "canal_bancaire.h"

int mode;
// 2 = président; 3 = banquier; 4 = directeur agence
int role;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     set_mode();
     color_mode();
     toolbar();
}

void MainWindow::set_role(int i)
{
    role = i;
}

// Choix darkmode ou mode normale selon qui s'est connecté sur l'application.
void MainWindow::set_mode(){
    // Président == darkmode
    if (role == 2)
        mode = 0;
    else
        mode = 1;
}

void MainWindow::set_vue()
{
    if (role == 2)
        this->vue_principale(mode);
    else
        this->vue_banquier(mode);
}

void MainWindow::vue_principale(int mode)
{
    principale* vue = new principale(this, mode);
    setCentralWidget(vue);
}

void MainWindow::vue_bancaire()
{
    if(role == 2){
    canal_bancaire* vue = new canal_bancaire(this, mode);
    setCentralWidget(vue);
    }
    else{
        QMessageBox *erreur = new QMessageBox();
        erreur->setBaseSize(QSize(800,600));
        erreur->setFixedSize(QSize(800,600));
        erreur->setInformativeText("Vous n'avez pas encore cette fonctionalité, elle sera ajoutée prochainement.");
        erreur->show();
    }
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
    if(role == 2 )
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

    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
    QMenu *theme = new QMenu("&Thème");
    QAction *dark_mode = new QAction("&Dark Mode", this);
    dark_mode->setIcon(QIcon(":/assets/darkmode.png"));
    QAction *sobre = new QAction("&Sobre",this);
    QAction *sature = new QAction("&Saturé",this);
    QAction *sombre = new QAction("&Sombre",this);
        theme->addAction(dark_mode);
    theme->addAction(sobre);
    theme->addAction(sature);
    theme->addAction(sombre);

    menuAffichage->addMenu(theme);

    QMenu *communication = menuBar()->addMenu("&Communication");
    QAction *annonce = new QAction("&Message à Tous", this);
    QMenu *message = new QMenu("&Message à un employé");
    QAction *ma_boite = new QAction("&Mes courriers",this);
    QAction *employe1 = new QAction("&Yanis Moujab",this);
    QAction *employe2 = new QAction("&Salma Antar",this);
    QAction *employe3 = new QAction("&Luc Robin",this);
    message->addAction(employe1);
    message->addAction(employe2);
    message->addAction(employe3);
    communication->addAction(annonce);
    communication->addMenu(message);
    communication->addAction(ma_boite);

    QMenu *menuAide = menuBar()->addMenu("&Aide");
    QAction *guide = new QAction("&Notice Utilisateur", this);
    QAction *signaler = new QAction("&Signaler un problème", this);
    menuAide->addAction(guide);
    menuAide->addAction(signaler);

    // ToolBar avec des icônes
    QAction *vue_pr = ui->mainToolBar->addAction(QIcon(":/assets/principale.png"),"&Vue Principale");
    QAction *vue_bancaire = ui->mainToolBar->addAction(QIcon(":/assets/bancaire.png"),"&Canal Bancaire");
    QAction *vue_pret = ui->mainToolBar->addAction(QIcon(":/assets/pret.png"),"&Famille Prêt");

    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    QHBoxLayout* spinLay = new QHBoxLayout(ui->mainToolBar);
    spinLay->setContentsMargins(0,0,10,0); // Here you set the spacing

    QAction *darkmode = ui->toolBarRight->addAction(QIcon(":/assets/darkmode.png"),"&Dark Mode");

    QComboBox *couleur = new QComboBox();
    couleur->addItem("Sobre");
    couleur->addItem("Saturé");
    couleur->addItem("Sombre");

    QLabel *for_couleur = new QLabel("Thème");
    ui->toolBarRight->addWidget(for_couleur);
    for_couleur->setContentsMargins(10,0,5,0);
    ui->toolBarRight->addWidget(couleur);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(1,10);
    slider->setValue(1);
    slider->setMaximumWidth(100);
    slider->setWindowIcon(QIcon(":/assets/bancaire.png"));

    QLabel *for_slider = new QLabel("Zoom");
    ui->toolBarRight->addWidget(for_slider);
    ui->toolBarRight->addWidget(slider);
    for_slider->setContentsMargins(15,0,5,0);
    ui->toolBarRight->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QHBoxLayout* spinLay2 = new QHBoxLayout(ui->toolBarRight);
    spinLay2->setContentsMargins(0,0,15,0); // Here you set the spacing

    QObject::connect( deconnexion, &QAction::triggered, this, &MainWindow::connection );
    QObject::connect( actionQuitter, &QAction::triggered, this, &QApplication::quit );
    QObject::connect( vue_pret, &QAction::triggered, this, &MainWindow::vue_pret );
    QObject::connect( vue_pr, &QAction::triggered, this, &MainWindow::set_vue );
    QObject::connect( dark_mode, &QAction::triggered, this, &MainWindow::color_mode );
    QObject::connect( guide, &QAction::triggered, this, &MainWindow::guide );
    QObject::connect( darkmode, &QAction::triggered, this, &MainWindow::color_mode );
    QObject::connect( vue_bancaire, &QAction::triggered, this, &MainWindow::vue_bancaire );
  //  QObject::connect( slider, &QAction::triggered, this, &MainWindow::vue_bancaire );
    //QObject::connect( couleur, &QAction::triggered, this, &MainWindow::color_mode );

}

void MainWindow::connection(){

    QMessageBox *erreur = new QMessageBox();
    erreur->setInformativeText("Pas encore implémenté, veuillez quitter et relancer l'application pour ouvrir une nouvelle session");
    erreur->show();
}

void MainWindow::color_mode()
{

    QPalette palette;
        if(mode == 0){
            palette.setColor(QPalette::Window, QColor(43, 43, 55));
            palette.setColor(QPalette::WindowText, QColor(205, 205, 225));
            palette.setColor(QPalette::Text, Qt::white);
            palette.setColor(QPalette::ToolTipBase, Qt::black);
            palette.setColor(QPalette::ToolTipText, QColor(43, 43, 55));
            palette.setColor(QPalette::ButtonText, QColor(43, 43, 55));
            palette.setColor(QPalette::HighlightedText, QColor(43, 43, 55));
            palette.setColor(QPalette::BrightText, QColor(43, 43, 55));
            palette.setColor(QPalette::Base, QColor(25, 25, 25));
            palette.setColor(QPalette::AlternateBase, QColor(43, 43, 55));
            palette.setColor(QPalette::ToolTipBase, Qt::black);
            palette.setColor(QPalette::Button, QColor(190, 190, 205));
            palette.setColor(QPalette::Link, QColor(42, 130, 218));
            palette.setColor(QPalette::Highlight, QColor(180, 180, 200));
            mode = 1;

        }
        else{
            palette.setColor(QPalette::Window, QColor(250, 250, 255));
            palette.setColor(QPalette::WindowText, QColor(103, 103, 125));
            palette.setColor(QPalette::Text, QColor(43, 43, 55));
            palette.setColor(QPalette::Base, QColor(236, 236, 236));
            palette.setColor(QPalette::AlternateBase, QColor(203, 203, 203));
            palette.setColor(QPalette::ToolTipBase, Qt::white);
            palette.setColor(QPalette::ToolTipText, QColor(43, 43, 55));
            palette.setColor(QPalette::Text, QColor(43, 43, 55));
            palette.setColor(QPalette::Button, QColor(105, 175, 195));
            palette.setColor(QPalette::ButtonText, QColor(43, 43, 55));
            palette.setColor(QPalette::BrightText, Qt::red);
            palette.setColor(QPalette::Link, QColor(42, 130, 218));
            palette.setColor(QPalette::Highlight, QColor(84, 154, 136));
            palette.setColor(QPalette::HighlightedText, Qt::white);
            mode = 0;
        }

    QApplication::setPalette(palette);
    this->setPalette(palette);
    this->set_vue();
}

MainWindow::~MainWindow()
{
    delete ui;
}


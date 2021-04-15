#include "connection.h"
#include "ui_connection.h"
#include "mainwindow.h"
#include <string.h>

connection::connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connection)
{
    ui->setupUi(this);
    handle_connections();
    color_mode();
}

void connection::handle_connections()
{
    QObject::connect( ui->login_button, &QPushButton::released, this, &connection::login );

}

void connection::login()
{
    //Président
    if(QString::compare(ui->login_input->text(), "président")==0 && QString::compare(ui->pass_input->text(), "")==0)
        this->done(2);
    //Banquier
    else if(QString::compare(ui->login_input->text(), "banquier")==0 && QString::compare(ui->pass_input->text(), "")==0)
        this->done(3);
    //Président
    else if(QString::compare(ui->login_input->text(), "")==0 && QString::compare(ui->pass_input->text(), "")==0)
        this->done(4);
    //Incorrecte
    else{
        ui->instructions->setText("Login ou Mot de passe incorrecte!");
        ui->instructions->setStyleSheet("QLabel { color : red; }");
    }
}

void connection::color_mode()
{


    QPalette palette;

   /* palette.setColor(QPalette::Window, QColor(53, 53, 53));
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
    palette.setColor(QPalette::Highlight, QColor(42, 130, 218));*/


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

    QApplication::setPalette(palette);
    this->setPalette(palette);
}

connection::~connection()
{
    delete ui;
}

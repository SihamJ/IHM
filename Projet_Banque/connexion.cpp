#include "connexion.h"
#include "ui_connexion.h"

connexion::connexion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::connexion)
{
    ui->setupUi(this);
}

connexion::~connexion()
{
    delete ui;
}

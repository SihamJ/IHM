#include "canal_pret.h"
#include "ui_canal_pret.h"

canal_pret::canal_pret(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::canal_pret)
{
    ui->setupUi(this);
}

canal_pret::~canal_pret()
{
    delete ui;
}

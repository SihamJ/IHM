#include "vue_banquier.h"
#include "ui_vue_banquier.h"

vue_banquier::vue_banquier(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vue_banquier)
{
    ui->setupUi(this);
}

vue_banquier::~vue_banquier()
{
    delete ui;
}

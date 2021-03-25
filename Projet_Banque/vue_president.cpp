#include "vue_president.h"
#include "ui_vue_president.h"

vue_president::vue_president(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vue_president)
{
    ui->setupUi(this);
}

vue_president::~vue_president()
{
    delete ui;
}

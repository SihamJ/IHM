#include "guide.h"
#include "ui_guide.h"

int darkmode_g = 0;

Guide::Guide(QWidget *parent, int mode) :
    QDialog(parent),
    ui(new Ui::Guide)
{
    darkmode_g = mode;
    ui->setupUi(this);
}

Guide::~Guide()
{
    delete ui;
}

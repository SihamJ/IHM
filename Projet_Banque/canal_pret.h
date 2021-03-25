#ifndef CANAL_PRET_H
#define CANAL_PRET_H

#include <QMainWindow>

namespace Ui {
class canal_pret;
}

class canal_pret : public QMainWindow
{
    Q_OBJECT

public:
    explicit canal_pret(QWidget *parent = nullptr);
    ~canal_pret();

private:
    Ui::canal_pret *ui;
};

#endif // CANAL_PRET_H

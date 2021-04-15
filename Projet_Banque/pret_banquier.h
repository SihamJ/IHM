#ifndef PRET_BANQUIER_H
#define PRET_BANQUIER_H

#include <QWidget>

namespace Ui {
class pret_banquier;
}

class pret_banquier : public QWidget
{
    Q_OBJECT

public:
    explicit pret_banquier(QWidget *parent = nullptr, int mode = 0);
    ~pret_banquier();
    void handle_connections();
    void pret(int i, QString titre);
    void set_up_ui();

public slots:
    void volume();
    void ca();
    void pourcentage();

private:
    Ui::pret_banquier *ui;
};

#endif // PRET_BANQUIER_H

#ifndef BANQUIER_H
#define BANQUIER_H

#include <QWidget>

namespace Ui {
class Banquier;
}

class Banquier : public QWidget
{
    Q_OBJECT

public:
    explicit Banquier(QWidget *parent = nullptr, QString name = nullptr, QString agence = nullptr);
    ~Banquier();
    void set_up_ui();
    void handle_connections();
    void produit_bancaire(int i, const QString);
    void produit_assur(int i, const QString);
    void produit_bours(int i, const QString);

public slots:
    void details_assur();
    void details_bours();
    void details_bq();
    void volume1();
    void ca1();
    void pourcentage1();
    void volume2();
    void ca2();
    void pourcentage2();
    void volume3();
    void ca3();
    void pourcentage3();


private:
    Ui::Banquier *ui;
};

#endif // BANQUIER_H

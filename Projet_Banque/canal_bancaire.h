#ifndef CANAL_BANCAIRE_H
#define CANAL_BANCAIRE_H

#include <QWidget>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QWidget>

namespace Ui {
class canal_bancaire;
}

class canal_bancaire : public QWidget
{
    Q_OBJECT

public:
    explicit canal_bancaire(QWidget *parent = nullptr, int mode=0);
    ~canal_bancaire();
    void handle_connections();
    void set_up_ui();
    void famille_pret(int i, const QString);
    void famille_comptes(int i, const QString);
    void famille_chequier(int i, const QString);

public slots:
    void details_pret();
    void details_comptes();
    void details_chequier();
    void volume1();
    void ca1();
    void pourcentage1();
    void volume2();
    void ca2();
    void pourcentage2();
    void volume3();
    void ca3();
    void pourcentage3();
    void changer_agence();
    void changer_banquier();

private:
    Ui::canal_bancaire *ui;
};

#endif // CANAL_BANCAIRE_H

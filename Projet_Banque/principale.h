#ifndef PRINCIPALE_H
#define PRINCIPALE_H

#include <QWidget>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QWidget>

namespace Ui {
class principale;
}

class principale : public QWidget
{
    Q_OBJECT

public:
    explicit principale(QWidget *parent = nullptr, int mode = 0);
    ~principale();
    void handle_connections();
    void set_up_ui();
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
    void changer_agence();
    void changer_banquier();

private:
    Ui::principale *ui;
};

#endif // PRINCIPALE_H

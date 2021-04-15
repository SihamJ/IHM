#ifndef DETAILS_H
#define DETAILS_H

#include <QDialog>
#include <QtCharts>
#include <QChart>


namespace Ui {
class details;
}

class details : public QDialog
{
    Q_OBJECT

public:
    explicit details(QWidget *parent = nullptr);
    ~details();
    void set_chart(int i, QString titre);
    void handle_connections();

public slots:
    void volume();
    void ca();
    void pourcentage();

private:
    Ui::details *ui;
};

#endif // DETAILS_H

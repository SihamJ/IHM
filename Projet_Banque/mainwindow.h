#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QtCharts/QChartView>
#include "pret.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void toolbar();
    void color_mode();
    void set_role(int i);
    void set_vue();

private:
    Ui::MainWindow *ui;

public slots:
    void vue_pret();
    void vue_banquier(int mode);
    void vue_principale(int mode);
    void guide();
    void connection();
};
#endif // MAINWINDOW_H

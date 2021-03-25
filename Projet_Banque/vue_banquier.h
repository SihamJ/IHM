#ifndef VUE_BANQUIER_H
#define VUE_BANQUIER_H

#include <QMainWindow>

namespace Ui {
class vue_banquier;
}

class vue_banquier : public QMainWindow
{
    Q_OBJECT

public:
    explicit vue_banquier(QWidget *parent = nullptr);
    ~vue_banquier();

private:
    Ui::vue_banquier *ui;
};

#endif // VUE_BANQUIER_H

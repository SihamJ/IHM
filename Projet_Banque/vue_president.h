#ifndef VUE_PRESIDENT_H
#define VUE_PRESIDENT_H

#include <QMainWindow>

namespace Ui {
class vue_president;
}

class vue_president : public QMainWindow
{
    Q_OBJECT

public:
    explicit vue_president(QWidget *parent = nullptr);
    ~vue_president();

private:
    Ui::vue_president *ui;
};

#endif // VUE_PRESIDENT_H

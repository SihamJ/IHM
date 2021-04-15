#ifndef GUIDE_H
#define GUIDE_H

#include <QDialog>

namespace Ui {
class Guide;
}

class Guide : public QDialog
{
    Q_OBJECT

public:
    explicit Guide(QWidget *parent = nullptr, int mode=0);
    ~Guide();

private:
    Ui::Guide *ui;
};

#endif // GUIDE_H

#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>

namespace Ui {
class connection;
}

class connection : public QDialog
{
    Q_OBJECT

public:
    explicit connection(QWidget *parent = nullptr);
    ~connection();
    void handle_connections();
    void color_mode();

public slots:
    void login();

private:
    Ui::connection *ui;
};

#endif // CONNECTION_H

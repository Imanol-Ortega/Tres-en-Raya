#ifndef CERRAR_H
#define CERRAR_H

#include <QDialog>

namespace Ui {
class cerrar;
}

class cerrar : public QDialog
{
    Q_OBJECT

public:
    explicit cerrar(QWidget *parent = nullptr);
    ~cerrar();
    bool can=true;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::cerrar *ui;
};

#endif // CERRAR_H

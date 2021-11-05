#include "cerrar.h"
#include "ui_cerrar.h"
#include "tresenraya.h"

cerrar::cerrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cerrar)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    setWindowTitle("Atención");
}

cerrar::~cerrar()
{
    delete ui;
}

void cerrar::on_pushButton_clicked()
{
    can=true;
    close();
}

void cerrar::on_pushButton_2_clicked()
{
    can=false;
    this->close();
}

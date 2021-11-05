#ifndef TRESENRAYA_H
#define TRESENRAYA_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QCloseEvent>
#include "cerrar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TresEnRaya; }
QT_END_NAMESPACE

class QImage;
class QPainter;
class QMediaPlayer;
class cerrar;


class TresEnRaya : public QMainWindow
{
    Q_OBJECT

public:
    TresEnRaya(QWidget *parent = nullptr);
    ~TresEnRaya();
    cerrar p;

    void cruz();
    void circle();
    void comprobacionx();
    void comprobaciono();
    void ganaste();
    void perdiste();
    void empate();
    void facil();
    void sonidoe();
    void sonidog();

protected:
    void paintEvent(QPaintEvent *pe) override;
    void mousePressEvent(QMouseEvent *pre) override;
    void closeEvent(QCloseEvent *e);
private slots:
    void on_Reiniciar_triggered();

    void on_Salir_triggered();

    void on_Color_X_triggered();

    void on_Color_O_triggered();

    void on_X_triggered();

    void on_O_triggered();

    void on_contra_triggered();


private:
    Ui::TresEnRaya *ui;
    QImage *mImage;
    QPainter *mPainter;
    QColor xcolor;
    QColor ocolor;
    QMediaPlayer *media;


    int cont = 1;
    int x;
    int y;
    int tres[4][4];
    int el=0;
    int aux=1;
    int j1=0;
    int j2=0;
    int em=0;
    int e1=0;
    int e2=0;
    int i=0;

};
#endif // TRESENRAYA_H

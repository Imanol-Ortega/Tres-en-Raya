#include "tresenraya.h"
#include "ui_tresenraya.h"
#include <QColorDialog>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QCloseEvent>
#include "cerrar.h"

TresEnRaya::TresEnRaya(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TresEnRaya)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
    media = new QMediaPlayer(this);

    mImage = new QImage(300,300,QImage::Format_A2BGR30_Premultiplied);
    mImage->fill(qRgb(255,255,255));
    mPainter = new QPainter(mImage);
    xcolor = QColor(Qt::black);
    ocolor = QColor(Qt::black);

}

TresEnRaya::~TresEnRaya()
{
    delete ui;
    delete mPainter;
    delete mImage;
}
void TresEnRaya::closeEvent(QCloseEvent *e)
{
    if(el!=0){
        p.exec();
        if(p.can==false){
            e->ignore();
        }
    }
}

void TresEnRaya::paintEvent(QPaintEvent *pe){
    QPainter painter(this);
    painter.drawImage(0,0,*mImage);
    painter.setPen(QPen(Qt::black,2));
    painter.drawLine(0,110,299,110);//y
    painter.drawLine(0,210,299,210);//y
    painter.drawLine(100,0,100,300);//x
    painter.drawLine(200,0,200,300);//x
    pe->accept();

}
void TresEnRaya::mousePressEvent(QMouseEvent *pre){

     x = pre->x();
     y = pre->y();

     on_contra_triggered();



     /*qDebug()<<x;
     qDebug()<<y;*/
     qDebug()<<el;

    update();
    pre->accept();
}



void TresEnRaya::cruz(){

    mPainter->setRenderHint(QPainter:: HighQualityAntialiasing);
    mPainter->setPen(QPen(xcolor,3));
    if(el<=9){
        if(x>0 && x<98 && y>0 && y<108){
            if(tres[1][1] != 2){
              mPainter->drawLine(20,40,80,90);
              mPainter->drawLine(20,90,80,40);
              tres[1][1] = 1;
              cont++;
              el++;
            }
        }
        else if(x>101 && x<199 && y>0 && y<108){
            if(tres[1][2] != 2){
                mPainter->drawLine(120,40,180,90);
                mPainter->drawLine(120,90,180,40);
                tres[1][2] = 1;
                cont++;
                el++;
            }
        }

        else if(x>201 && x<299 && y>0 && y<108){
            if(tres[1][3] != 2){
                mPainter->drawLine(220,40,280,90);
                mPainter->drawLine(220,90,280,40);
                tres[1][3] = 1;
                cont++;
                el++;
            }
        }
        else if(x>0 && x<98 && y>110 && y<210){
            if(tres[2][1] != 2){
                mPainter->drawLine(20,135,80,185);
                mPainter->drawLine(20,185,80,135);
                tres[2][1] = 1;
                cont++;
                el++;
            }

        }
        else if(x>101 && x<199 && y>110 && y<210){
            if(tres[2][2] != 2){
                mPainter->drawLine(120,135,180,185);
                mPainter->drawLine(120,185,180,135);
                tres[2][2] = 1;
                cont++;
                el++;
            }
        }
        else if(x>201 && x<299 && y>110 && y<210){
            if(tres[2][3] != 2){
                mPainter->drawLine(220,135,280,185);
                mPainter->drawLine(220,185,280,135);
                tres[2][3] = 1;
                cont++;
                el++;
            }
        }
        else if(x>0 && x<99 && y>210 && y<299){
            if(tres[3][1] != 2){
                mPainter->drawLine(20,230,80,280);
                mPainter->drawLine(20,280,80,230);
                tres[3][1] = 1;
                cont++;
                el++;
            }
        }
        else if(x>101 && x<199 && y>210 && y<299){
            if(tres[3][2] != 2){
                mPainter->drawLine(120,230,180,280);
                mPainter->drawLine(120,280,180,230);
                tres[3][2] = 1;
                cont++;
                el++;
            }
        }
        else if(x>201 && x<299 && y>210 && y<299){
            if(tres[3][3] != 2){
                mPainter->drawLine(220,230,280,280);
                mPainter->drawLine(220,280,280,230);
                tres[3][3] = 1;
                cont++;
                el++;
            }
        }
    }
}

void TresEnRaya::circle(){

    mPainter->setRenderHint(QPainter:: HighQualityAntialiasing);
    mPainter->setPen(QPen(ocolor,3));
    if(el<=9){
        //Dibujando el circle
        if(x>0 && x<98 && y>0 && y<108){
            if(tres[1][1] != 1){
                mPainter->drawEllipse(15,28,70,70);
                tres[1][1] = 2;
                cont++;
                el++;
            }
        }
        else if(x>101 && x<199 && y>0 && y<108){
            if(tres[1][2] != 1){
                mPainter->drawEllipse(115,28,70,70);
                tres[1][2] = 2;
                cont++;
                el++;
            }
        }

        else if(x>201 && x<299 && y>0 && y<108){
            if(tres[1][3] != 1){
                mPainter->drawEllipse(215,28,70,70);
                tres[1][3] = 2;
                cont++;
                el++;
            }
        }
        else if(x>0 && x<98 && y>110 && y<210){
            if(tres[2][1] != 1){
                mPainter->drawEllipse(14,126,70,70);
                tres[2][1] = 2;
                cont++;
                el++;
            }
        }
        else if(x>101 && x<199 && y>110 && y<210){
            if(tres[2][2] != 1){
                mPainter->drawEllipse(114,126,70,70);
                tres[2][2] = 2;
                cont++;
                el++;
            }
        }
        else if(x>201 && x<299 && y>110 && y<210){
            if(tres[2][3] != 1){
                mPainter->drawEllipse(214,126,70,70);
                tres[2][3] = 2;
                cont++;
                el++;
            }
        }
        else if(x>0 && x<99 && y>210 && y<299){
            if(tres[3][1] != 1){
                mPainter->drawEllipse(14,222,70,70);
                tres[3][1] = 2;
                cont++;
                el++;
            }
        }
        else if(x>101 && x<199 && y>210 && y<299){
            if(tres[3][2] != 1){
                mPainter->drawEllipse(114,222,70,70);
                tres[3][2] = 2;
                cont++;
                el++;
            }
        }
        else if(x>201 && x<299 && y>210 && y<299){
            if(tres[3][3] != 1){
                mPainter->drawEllipse(214,222,70,70);
                tres[3][3] = 2;
                cont++;
                el++;
            }
        }

    }
}

void TresEnRaya::comprobaciono(){
 mPainter->setPen(QPen(ocolor,4));
    if(tres[1][1] == 2 && tres[1][2]== 2 && tres[1][3] == 2){//1
        mPainter->drawLine(9,64,290,64);
        perdiste();
        return;
    }
    else if(tres[2][1] == 2 && tres[2][2]== 2 && tres[2][3] == 2){//2
        mPainter->drawLine(9,158,290,158);
        perdiste();
        return;
    }
    else if(tres[3][1] == 2 && tres[3][2]== 2 && tres[3][3] == 2){//3
        mPainter->drawLine(9,256,290,256);
        perdiste();
        return;
    }
    else if(tres[1][1] == 2 && tres[2][1]== 2 && tres[3][1] == 2){//4
        mPainter->drawLine(50,35,50,285);
        perdiste();
        return;
    }
    else if(tres[1][2] == 2 && tres[2][2]== 2 && tres[3][2] == 2){//5
        mPainter->drawLine(150,35,150,285);
        perdiste();
        return;
    }
    else if(tres[1][3] == 2 && tres[2][3]== 2 && tres[3][3] == 2){//6
        mPainter->drawLine(250,35,250,285);
        perdiste();
        return;
    }
    else if(tres[1][1] == 2 && tres[2][2]== 2 && tres[3][3] == 2){//7
        mPainter->drawLine(9,25,290,290);
        perdiste();
        return;
    }
    else if(tres[3][1] == 2 && tres[2][2]== 2 && tres[1][3] == 2){//8
        mPainter->drawLine(295,20,15,290);
        perdiste();
        return;
    }

}

void TresEnRaya::comprobacionx(){
    mPainter->setPen(QPen(xcolor,4));

            if(tres[1][1] == 1 && tres[1][2]== 1 && tres[1][3] == 1){//1
                mPainter->drawLine(9,64,290,64);
                ganaste();
                return;
            }
            else if(tres[2][1] == 1 && tres[2][2]== 1 && tres[2][3] == 1){//2
                mPainter->drawLine(9,158,290,158);
                ganaste();
                return;
            }
            else if(tres[3][1] == 1 && tres[3][2]== 1 && tres[3][3] == 1){//3
                mPainter->drawLine(9,256,290,256);
                ganaste();
                return;
            }
            else if(tres[1][1] == 1 && tres[2][1]== 1 && tres[3][1] == 1){//4
                mPainter->drawLine(50,35,50,285);
                ganaste();
                return;
            }
            else if(tres[1][2] == 1 && tres[2][2]== 1 && tres[3][2] == 1){//5
                mPainter->drawLine(150,35,150,285);
                ganaste();
                return;
            }
            else if(tres[1][3] == 1 && tres[2][3]== 1 && tres[3][3] == 1){//6
                mPainter->drawLine(250,35,250,285);
                ganaste();
                return;
            }
            else if(tres[1][1] == 1 && tres[2][2]== 1 && tres[3][3] == 1){//7
                mPainter->drawLine(9,25,290,290);
                ganaste();
                return;
            }
            else if(tres[3][1] == 1 && tres[2][2]== 1 && tres[1][3] == 1){//8
                mPainter->drawLine(295,25,15,295);
                ganaste();
                return;
            }

}

void TresEnRaya::ganaste(){

    sonidog();
    el=10;
    j1++;
    ui->jugador1->setText(QString::number(j1));
    QMessageBox::information(this,"","Ganó X     ");


}

void TresEnRaya::perdiste(){
    sonidog();
    el=10;
    j2++;
    ui->jugador2->setText(QString::number(j2));
    QMessageBox::information(this,"","Gano O     ");

}

void TresEnRaya::empate(){
    em++;
    ui->empate->setText(QString::number(em));
    QMessageBox::information(this,"","Empate       ");

}

void TresEnRaya::sonidoe()
{
    media->setMedia(QUrl::fromLocalFile("D:/QT programing/Tres_en_Raya/windows-exclamacion.mp3"));
    media->setVolume(50);
    media->play();
}

void TresEnRaya::sonidog()
{
    media->setMedia(QUrl::fromLocalFile("D:/QT programing/Tres_en_Raya/mario-bros-woo-hoo.mp3"));
    media->setVolume(50);
    media->play();
}


void TresEnRaya::on_Reiniciar_triggered()
{
    mImage->fill(qRgb(255,255,255));
    cont=aux;
    el=0;
    e1=0;
    e2=0;
    for (int x=0;x<4;x++) {
        for (int y=0;y<4;y++) {
            tres[x][y]=0;
        }

    }
    update();

}

void TresEnRaya::on_Salir_triggered()
{
    close();
}


void TresEnRaya::on_Color_X_triggered()
{
    if(el==0){
        xcolor = QColorDialog::getColor(Qt::black,this,"Color de la X");
    }
    else{

        sonidoe();
        QMessageBox::critical(this,"Error","No se puede cambiar el color una vez empezado el juego");
    }

}

void TresEnRaya::on_Color_O_triggered()
{
    if(el==0){
        ocolor = QColorDialog::getColor(Qt::black,this,"Color del circulo");
    }
    else{
        sonidoe();
        QMessageBox::critical(this,"Error","No se puede cambiar el color una vez empezado el juego");
    }
}

void TresEnRaya::on_X_triggered()
{

    if(el==0){
        cont=1;
        aux=1;
    }else{
        sonidoe();
        QMessageBox::critical(this,"Error","No se puede cambiar la ficha  una vez empezado el juego");
    }

}

void TresEnRaya::on_O_triggered()
{

    if(el==0){
        cont=0;
        aux=0;

    }else{
        sonidoe();
        QMessageBox::critical(this,"Error","No se puede cambiar la ficha  una vez empezado el juego");

    }
}

void TresEnRaya::on_contra_triggered()
{
    if(cont%2 !=0){
       cruz();
       comprobacionx();
    }
    else if(cont%2 ==0){
       circle();
       comprobaciono();
    }
    if(el==9){
        empate();
    }
}






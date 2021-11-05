#include "music.h"
#include "ui_music.h"
#include <QFileInfo>

Music::Music(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Music)
{
    ui->setupUi(this);
    music = new QMediaPlayer;
    this->setFixedSize(this->width(),this->height());

    ui->back->setIcon(QIcon(":/Back.ico"));
    ui->next->setIcon(QIcon(":/Next.ico"));
    ui->play->setIcon(QIcon(":/Play.ico"));
    ui->pause->setIcon(QIcon(":/Pause.ico"));

   connect(music,&QMediaPlayer::positionChanged,[&](qint64 pos){
        ui->progressBar->setValue(pos);
    });
    connect(music,&QMediaPlayer::durationChanged, [&](qint64 dur){
       ui->progressBar->setMaximum(dur);
    });
}

Music::~Music()
{
    delete ui;
}

void Music::on_Abrir_clicked()
{
    File = QFileDialog::getOpenFileName(this,"Abrir");
    music->setMedia(QUrl::fromLocalFile(File));
    music->setVolume(ui->Volumen->value());
    QFileInfo f(File);
    nfile = f.fileName();
    ui->nombrearchivo->setText(nfile);


    on_play_clicked();

}
void Music::on_Volumen_valueChanged(int value)
{
    music->setVolume(value);
    a=value;
    ui->nvol->setText(QString::number(a));
}

void Music::on_back_clicked()
{

}

void Music::on_next_clicked()
{

}

void Music::on_pause_clicked()
{
     music->pause();
}

void Music::on_play_clicked()
{
     music->play();
}

#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>

#include <QMediaPlayer>
#include <QString>
#include <QFileInfo>
#include <QFileDialog>

namespace Ui {

class QMediaPlayer;
class Music;
}

class Music : public QWidget
{
    Q_OBJECT

public:
    explicit Music(QWidget *parent = nullptr);
    ~Music();

private slots:
    void on_Abrir_clicked();

    void on_Volumen_valueChanged(int value);

    void on_back_clicked();

    void on_next_clicked();

    void on_pause_clicked();

    void on_play_clicked();

private:
    Ui::Music *ui;
    QMediaPlayer *music;
    QString File,nfile;
    int a=0;
};

#endif // MUSIC_H

#pragma once

#include "ui_player.h"
#include <QMediaPlayer>
#include <QVideoWidget>

class Player : public QWidget
{
    Q_OBJECT
public:
    Player(QWidget* parent = nullptr);
    ~Player();

private:
    Ui::PlayerClass* ui;

    QMediaPlayer* m_player;
    QVideoWidget* m_videoWgt;

    QVector<QString> videoUrls;

    void initUi();

    void initConnect();

    void playVideo();

    void playNextSegment();
};
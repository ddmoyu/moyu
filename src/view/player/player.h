#pragma once

#include "ui_player.h"

class Player : public QWidget
{
    Q_OBJECT
public:
    Player(QWidget* parent = nullptr);
    ~Player();

private:
    Ui::PlayerClass* ui;
};
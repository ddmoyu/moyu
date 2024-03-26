#include "player.h"

Player::Player(QWidget* parent) 
: QWidget(parent)
, ui(new Ui::PlayerClass())
{
    ui->setupUi(this);
}

Player::~Player() {}
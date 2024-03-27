#pragma once

#include "ui_main.h"
#include "../../utils/utils.h"
#include "../manager/manager.h"
#include "../player/player.h"

class Main : public QWidget
{
    Q_OBJECT
public:
    Main(QWidget* parent = nullptr);
    ~Main();

private:
    Ui::MainClass* ui;
    Manager* m_manager;
    Player* m_player;

    void initUi();

    void initConnect();
};

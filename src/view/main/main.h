#pragma once

#include "ui_main.h"
#include "../../utils/utils.h"

class Main : public QWidget
{
    Q_OBJECT
public:
    Main(QWidget* parent = nullptr);
    ~Main();

private:
    Ui::MainClass* ui;

    void initUi();
};
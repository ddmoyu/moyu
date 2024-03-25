#pragma once

#include "ui_main.h"

class Main : public QWidget
{
    Q_OBJECT
public:
    Main(QWidget* parent = nullptr);
    ~Main();

private:
    Ui::MainClass* ui;
};
#pragma once

#include "ui_moyu.h"

class MoYu : public QWidget
{
    Q_OBJECT
public:
    MoYu(QWidget* parent = nullptr);
    ~MoYu();

private:
    Ui::MoYuClass* ui;
};
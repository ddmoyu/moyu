#pragma once

#include "ui_manager.h"

class Manager : public QWidget
{
    Q_OBJECT
public:
    Manager(QWidget* parent = nullptr);
    ~Manager();

private:
    Ui::managerClass* ui;
};
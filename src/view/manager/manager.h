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

    void initUi();

    void initConnect();

    void addFeedLink();

    void feedLinkRequest(const QString& url);

    void testHttpsRequest();

    void showRemoteImage();
};
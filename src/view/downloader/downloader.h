#pragma once

#include "ui_downloader.h"

class Downloader : public QWidget
{
    Q_OBJECT
public:
    Downloader(QWidget* parent = nullptr);
    ~Downloader();

private:
    Ui::DownloaderClass* ui;
};
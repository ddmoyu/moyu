#include "downloader.h"

Downloader::Downloader(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::DownloaderClass())
{
    ui->setupUi(this);
}

Downloader::~Downloader() { }
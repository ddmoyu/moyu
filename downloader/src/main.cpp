#include "views/downloader.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Downloader w;
    w.show();
    return a.exec();
}
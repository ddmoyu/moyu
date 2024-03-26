#include <QApplication>
#include <singleapplication.h>
#include "view/main/main.h"

int main(int argc, char* argv[])
{
    SingleApplication app(argc, argv);
    Main m;

    QObject::connect(&app, &SingleApplication::instanceStarted, [&m]() {
        m.raise();
        m.activateWindow();
    });

    m.show();
    return app.exec();
}
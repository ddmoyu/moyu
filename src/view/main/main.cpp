#include "main.h"

Main::Main(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::MainClass())
{
    ui->setupUi(this);
    initUi();
}

Main::~Main() { }

void Main::initUi()
{
    const QString style = Util::invokeStyleSheetLoad("dark");
    setStyleSheet(style);
}

#include "main.h"

Main::Main(QWidget* parent) 
: QWidget(parent)
, ui(new Ui::MainClass())
{
    ui->setupUi(this);
}

Main::~Main() {}
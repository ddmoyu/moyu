#include "manager.h"

Manager::Manager(QWidget* parent) 
: QWidget(parent)
, ui(new Ui::managerClass())
{
    ui->setupUi(this);
}

Manager::~Manager() {}
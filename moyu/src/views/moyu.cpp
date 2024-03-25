#include "moyu.h"

MoYu::MoYu(QWidget* parent) 
: QWidget(parent)
, ui(new Ui::MoYuClass())
{
    ui->setupUi(this);
}

MoYu::~MoYu() {}
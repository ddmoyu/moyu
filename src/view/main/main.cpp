﻿#include "main.h"
#include "../manager/manager.h"

Main::Main(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::MainClass())
{
    ui->setupUi(this);
    initUi();
    initConnect();

    m_manager = new Manager(nullptr);
    m_manager->hide();
    m_player = new Player(nullptr);
    m_player->hide();
}

Main::~Main() { }

void Main::initUi()
{
    const QString style = invokeStyleSheetLoad("dark");
    setStyleSheet(style);
}

void Main::initConnect()
{
    connect(ui->btn_novel, &QPushButton::clicked, [&]() {
        ui->body_wgt->setCurrentIndex(0);
    });
    connect(ui->btn_image, &QPushButton::clicked, [&]() {
        ui->body_wgt->setCurrentIndex(1);
    });
    connect(ui->btn_video, &QPushButton::clicked, [&]() {
        ui->body_wgt->setCurrentIndex(2);
    });
    connect(ui->btn_iptv, &QPushButton::clicked, [&]() {
        ui->body_wgt->setCurrentIndex(3);
    });
    connect(ui->btn_jiexi, &QPushButton::clicked, [&]() {
        ui->body_wgt->setCurrentIndex(4);
    });
    connect(ui->btn_favorite, &QPushButton::clicked, [&]() {
        ui->body_wgt->setCurrentIndex(5);
    });
    connect(ui->btn_settings, &QPushButton::clicked, [&]() {
        ui->body_wgt->setCurrentIndex(6);
    });

    connect(ui->btn_manager, &QPushButton::clicked, [&]() {
        m_manager->show();
    });
    connect(ui->btn_player, &QPushButton::clicked, [&]() {
        m_player->show();
    });
}

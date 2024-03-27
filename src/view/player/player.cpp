#include "player.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
// #include <QMediaContent>

Player::Player(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::PlayerClass())
{
    ui->setupUi(this);
    initUi();
    initConnect();
}

Player::~Player() { }

void Player::initUi()
{
    m_player   = new QMediaPlayer(ui->player);
    m_videoWgt = new QVideoWidget(ui->player);
    m_videoWgt->resize(480, 360);
    m_player->setVideoOutput(m_videoWgt);

    QNetworkRequest req(QUrl("https://cdn.wlcdn99.com:777/32bca498/index.m3u8"));

    // "C:\Users\Hunlongyu\Downloads\0000.ts"
    // m_player->setSource(QUrl("https://cdn.wlcdn99.com:777/32bca498/index.m3u8"));

    // m_player->setSource(QUrl("C:/Users/Hunlongyu/Downloads/0000.ts"));
    // m_player->setSource(QUrl("https://cdn.wlcdn99.com:777/32bca498/0001.ts"));
}

void Player::initConnect()
{
    connect(ui->btn_play, &QPushButton::clicked, [this]() {
        playVideo();
    });
    connect(ui->btn_pause, &QPushButton::clicked, [this]() {
        m_player->pause();
    });
    connect(ui->btn_stop, &QPushButton::clicked, [this]() {
        m_player->stop();
    });
}

void Player::playVideo()
{
    m_player->play();

    // download ts and play it;

    // auto networkManager = new QNetworkAccessManager(this);
    ////https://cdn.wlcdn99.com:777/32bca498/0001.ts
    // QUrl url("https://cdn.wlcdn99.com:777/32bca498/index.m3u8");
    // networkManager->get(QNetworkRequest(url));
    // connect(networkManager, &QNetworkAccessManager::finished, this, [this](QNetworkReply* reply) {
    //     qDebug() << "request successfully";
    //     int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //     qDebug() << "code: " << code;
    //     if (reply->error() != QNetworkReply::NoError || code != 200) {
    //         qDebug() << reply->errorString().toLatin1().data();
    //     }
    //     else {
    //         QString m3u8     = reply->readAll();
    //         QStringList urls = m3u8.split("\n");
    //         for (const QString& url : urls) {
    //             if (url.endsWith(".ts")) {
    //                 videoUrls.append(url.trimmed());
    //             }
    //         }
    //         playNextSegment();
    //     }
    //     reply->deleteLater();
    // });
}

void Player::playNextSegment()
{
    if (!videoUrls.isEmpty()) {
        /*QMediaContent media(QUrl(videoUrls.first()));
        player.setMedia(media);
        player.play();*/
        m_player->setSource(QUrl(videoUrls.first()));
        videoUrls.removeFirst();
    }
}
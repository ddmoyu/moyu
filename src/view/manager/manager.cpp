#include "manager.h"

#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>

Manager::Manager(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::managerClass())
{
    ui->setupUi(this);
    initUi();
    initConnect();
}

Manager::~Manager() { }

void Manager::initUi() { }

void Manager::initConnect()
{
    connect(ui->btn_test_https, &QPushButton::clicked, this, &Manager::testHttpsRequest);
    connect(ui->btn_test_image, &QPushButton::clicked, this, &Manager::showRemoteImage);
}

void Manager::testHttpsRequest()
{
    auto networkManager = new QNetworkAccessManager(this);
    // QUrl url("https://collect.wolongzyw.com/api.php/provide/vod/?ac=videolist&pg=2"); // page n videolist
    QUrl url("https://collect.wolongzyw.com/api.php/provide/vod/?ac=videolist&ids=69733");
    networkManager->get(QNetworkRequest(url));
    connect(networkManager, &QNetworkAccessManager::finished, this, [](QNetworkReply* reply) {
        qDebug() << "request successfully";
        int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "code: " << code;
        if (reply->error() != QNetworkReply::NoError || code != 200) {
            qDebug() << reply->errorString().toLatin1().data();
        }
        else {
            QByteArray buff = reply->readAll();
            qDebug() << buff.data();
        }
        reply->deleteLater();
    });
}

void Manager::showRemoteImage()
{
    QUrl url("https://pic.wlongimg.com//upload/vod/20240220-1/311fc4f15600830fd10fb739f7ccf66b.jpg");
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request(url);
    QNetworkReply* reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, [reply, this]() {
        if (reply->error()) {
            qDebug() << "Error: " << reply->errorString();
            reply->deleteLater();
            return;
        }

        // 假设你已经有一个 QLabel *label， 你想显示图片
        QLabel* label = ui->lb_test_image;

        QPixmap pixmap;
        pixmap.loadFromData(reply->readAll());

        // 根据需要调整图片尺寸，这一步是可选的
        // pixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);

        label->setPixmap(pixmap);
        label->show();

        reply->deleteLater();
    });
    // lb_test_image
}

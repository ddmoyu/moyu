#include "manager.h"
#include "../../utils/videoUtils/videoUtils.h"

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
    connect(ui->btn_feed_add, &QToolButton::clicked, this, &Manager::addFeedLink);
    /*connect(ui->btn_test_https, &QPushButton::clicked, this, &Manager::testHttpsRequest);
    connect(ui->btn_test_image, &QPushButton::clicked, this, &Manager::showRemoteImage);*/
}

void Manager::addFeedLink()
{
    QString str = ui->le_feed->text();
}

void Manager::feedLinkRequest(const QString& url)
{
    const QString testApi = "https://gist.githubusercontent.com/ddmoyu/390a12610fb283ca7fe9bd80f0b04935/raw/5194f2843f78ff48aca4193630ce077d2cbb516b/feed.json";
}

void Manager::testHttpsRequest()
{
    const QString api("http://cj.lziapi.com/api.php/provide/vod/");
    // const QString api("https://api.maozyapi.com/inc/api.php");

    // ReSharper disable once CppExpressionWithoutSideEffects
    getVideoData(api)
        .then([&](const VideoData& data) {
            auto d = data;
            if (d.videoList.size() <= 0) {
                return;
            }
            for (const auto v : d.videoList) {
                /*ui->result->appendPlainText(QString::fromStdString(v.vod_name));
                const auto urls = v.vod_play_url;
                for (auto u : urls) {
                    ui->result->appendPlainText(QString::fromStdString(u.episode));
                    ui->result->appendPlainText(QString::fromStdString(u.url));
                }*/
            }
        })
        .fail([]() {
            qDebug() << "get video list failed!";
        })
        .finally([]() {
            qDebug() << "get video list finished!";
        });

    // QUrl url("https://collect.wolongzyw.com/api.php/provide/vod/?ac=videolist&pg=1"); // page n videolist
    // QUrl url("https://collect.wolongzyw.com/api.php/provide/vod/?ac=videolist&ids=69733"); // video detail
    // QUrl url("https://collect.wolongzyw.com/api.php/provide/vod/?wd=1");
}

void Manager::showRemoteImage()
{
    // QUrl url("https://pic.wlongimg.com//upload/vod/20240220-1/311fc4f15600830fd10fb739f7ccf66b.jpg");
    // QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    // QNetworkRequest request(url);
    // QNetworkReply* reply = manager->get(request);
    // connect(reply, &QNetworkReply::finished, [reply, this]() {
    //     if (reply->error()) {
    //         qDebug() << "Error: " << reply->errorString();
    //         reply->deleteLater();
    //         return;
    //     }

    //    // 假设你已经有一个 QLabel *label， 你想显示图片
    //    QLabel* label = ui->lb_test_image;

    //    QPixmap pixmap;
    //    pixmap.loadFromData(reply->readAll());

    //    // 根据需要调整图片尺寸，这一步是可选的
    //    // pixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    //    label->setPixmap(pixmap);
    //    label->show();

    //    reply->deleteLater();
    //});
    // lb_test_image
}

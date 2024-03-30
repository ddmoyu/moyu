#include "utils.h"

#include <QNetworkAccessManager>
#include <sass.h>
#include <QStringLiteral>
#include <QNetworkReply>

QString invokeStyleSheetLoad(const QString& qValue)
{
    const auto path    = QStringLiteral("../../../src/assets/style/%1/%1.sass").arg(qValue);
    const auto root    = sass_make_file_context(path.toStdString().c_str());
    const auto context = sass_file_context_get_context(root);
    const auto option  = sass_context_get_options(context);
    sass_option_set_precision(option, 2);
    sass_option_set_output_style(option, SASS_STYLE_COMPACT);
    sass_compile_file_context(root);
    if (sass_context_get_error_status(context) != 0) {
        qFatal(sass_context_get_error_message(context));
        return QString();
    }

    const auto styleSheet = QString::fromStdString(sass_context_get_output_string(context));
    sass_delete_file_context(root);
    return styleSheet;
}

VideoSimpleData getVideoSimpleData(const QString& api)
{
    VideoSimpleData data;
    /*const auto networkManager = new QNetworkAccessManager();
    networkManager->get(QNetworkRequest(QUrl(api)));
    connect(networkManager, &QNetworkAccessManager::finished, [](QNetworkReply* reply, VideoSimpleData data) {
        qDebug() << "request successfully";
        const int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "code: " << code;
        if (reply->error() != QNetworkReply::NoError || code != 200) {
            qDebug() << reply->errorString().toLatin1().data();
            return nullptr;
        }
        else {
            QByteArray buff = reply->readAll();
            qDebug() << buff.data();
            data.code = 1;
        }
        reply->deleteLater();
    });*/
    return data;
}

QtPromise::QPromise<QString> testPromise(const QUrl& api)
{
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    return QtPromise::QPromise<QString>{[manager, api](const QtPromise::QPromiseResolve<QString>& resolve, const QtPromise::QPromiseReject<QString>& reject) {
        QNetworkReply* reply = manager->get(QNetworkRequest{api});
        QObject::connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                const QString res = reply->readAll();
                resolve(res);
            }
            else {
                reject(QString());
            }
            reply->deleteLater();
        });
    }};
};

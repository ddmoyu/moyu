#include "videoUtils.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <regex>
#include <unordered_set>

/********************   JSON parser start   ********************/
VideoSimpleItem parseJsonVideoSimpleItem(const dom::object& obj)
{
    VideoSimpleItem item;
    item.vod_id        = obj["vod_id"].get_int64().value();
    item.vod_name      = obj["vod_name"].get_string().value();
    item.type_id       = obj["type_id"].get_int64().value();
    item.type_name     = obj["type_name"].get_string().value();
    item.vod_en        = obj["vod_en"].get_string().value();
    item.vod_time      = obj["vod_time"].get_string().value();
    item.vod_remarks   = obj["vod_remarks"].get_string().value();
    item.vod_play_from = obj["vod_play_from"].get_string().value();
    return item;
}
VideoItem parseJsonVideoItem(const dom::object& obj)
{
    VideoItem item;
    item.vod_id        = obj["vod_id"].get_int64().value();
    item.type_id       = obj["type_id"].get_int64().value();
    item.type_id_1     = obj["type_id_1"].get_int64().value();
    item.vod_name      = obj["vod_name"].get_string().value();
    item.vod_en        = obj["vod_en"].get_string().value();
    item.vod_pic       = obj["vod_pic"].get_string().value();
    item.vod_actor     = obj["vod_actor"].get_string().value();
    item.vod_director  = obj["vod_director"].get_string().value();
    item.vod_remarks   = obj["vod_remarks"].get_string().value();
    item.vod_pubdate   = obj["vod_pubdate"].get_string().value();
    item.vod_area      = obj["vod_area"].get_string().value();
    item.vod_lang      = obj["vod_lang"].get_string().value();
    item.vod_year      = obj["vod_year"].get_string().value();
    item.vod_state     = obj["vod_state"].get_string().value();
    item.vod_time      = obj["vod_time"].get_string().value();
    item.type_name     = obj["type_name"].get_string().value();
    item.vod_play_note = obj["vod_play_note"].get_string().value();

    const auto urls   = obj["vod_play_url"].get_string().value();
    item.vod_play_url = parseJsonVideoUrls(urls.data(), item.vod_play_note);
    return item;
}
VideoClassType parseJsonVideoClassType(const dom::object& obj)
{
    VideoClassType classType;
    classType.type_id   = obj["type_id"].get_int64().value();
    classType.type_name = obj["type_name"].get_string().value();
    return classType;
}
VideoSimpleData parseJsonVideoSimpleData(const std::string& jsonContent)
{
    dom::parser parser;
    auto result = parser.parse(jsonContent);
    if (result.error()) {
        throw std::runtime_error("json parser error");
    }

    VideoSimpleData data;
    const dom::object json = result.value().get_object();
    parseJsonVideoBase(data, json);

    const dom::array videoListArr = json["list"].get_array().value();
    for (dom::element videoItem : videoListArr) {
        data.videoList.push_back(parseJsonVideoSimpleItem(videoItem.get_object().value()));
    }

    const dom::array classListArr = json["class"].get_array().value();
    for (dom::element classItem : classListArr) {
        data.classList.push_back(parseJsonVideoClassType(classItem.get_object().value()));
    }

    return data;
}
void parseJsonVideoBase(VideoBase& base, const dom::object& json)
{
    base.code = json["code"].get_int64().value();
    base.msg  = json["msg"].get_string().value();

    const auto page = json["page"];
    if (page.is_int64()) {
        base.page = page.get_int64().value();
    }
    else if (page.is_string()) {
        const std::string_view _page = page.get_string().value();
        base.page                    = std::stoi(_page.data());
    }

    const auto pagecount = json["pagecount"];
    if (pagecount.is_int64()) {
        base.pagecount = pagecount.get_int64().value();
    }
    else if (pagecount.is_string()) {
        const std::string_view _pagecount = pagecount.get_string().value();
        base.pagecount                    = std::stoi(_pagecount.data());
    }

    const auto limit = json["limit"];
    if (limit.is_int64()) {
        base.limit = limit.get_int64().value();
    }
    else if (limit.is_string()) {
        const std::string_view _limit = limit.get_string().value();
        base.limit                    = std::stoi(_limit.data());
    }

    const auto total = json["total"];
    if (total.is_int64()) {
        base.total = total.get_int64().value();
    }
    else if (total.is_string()) {
        const std::string_view _total = total.get_string().value();
        base.total                    = std::stoi(_total.data());
    }
}
std::vector<VideoUrls> parseJsonVideoUrls(const std::string& input, const std::string& separator)
{
    std::vector<VideoUrls> urls;
    std::unordered_set<std::string> uniqueUrls;
    // 正则表达式现在指定以 .m3u8 结尾的 URL
    std::regex url_pattern(R"(([^#$]+)\$(https?://[^#]+\.m3u8))");

    // 如果separator不为空，我们首先根据separator分割输入的字符串
    std::vector<std::string> parts;
    if (!separator.empty()) {
        std::regex sep_pattern(separator); // 使用separator作为正则表达式

        std::sregex_token_iterator iter(input.begin(), input.end(), sep_pattern, -1);
        std::sregex_token_iterator end;
        for (; iter != end; ++iter) {
            parts.push_back(*iter); // 添加分割后的部分到parts向量中
        }
    }
    else {
        // 如果separator为空，则整个输入是一个部分
        parts.push_back(input);
    }

    // 解析每一部分寻找URL
    for (const auto& part : parts) {
        auto matches_begin = std::sregex_iterator(part.begin(), part.end(), url_pattern);
        auto matches_end   = std::sregex_iterator();

        for (std::sregex_iterator i = matches_begin; i != matches_end; ++i) {
            std::smatch match = *i;
            if (match.size() == 3) { // 正确匹配组大小为3
                std::string episode = match[1].str();
                std::string url     = match[2].str();

                // 保证URL的独特性
                if (uniqueUrls.find(url) == uniqueUrls.end()) {
                    urls.push_back({episode, url});
                    uniqueUrls.insert(url);
                }
            }
        }
    }
    return urls;
}
VideoData parserJsonVideoData(const std::string& jsonContent)
{
    dom::parser parser;
    auto result = parser.parse(jsonContent);
    if (result.error()) {
        throw std::runtime_error("json parser error");
    }

    VideoData data;
    const dom::object json = result.value().get_object();
    parseJsonVideoBase(data, json);

    const dom::array videoListArr = json["list"].get_array().value();
    for (dom::element videoItem : videoListArr) {
        data.videoList.push_back(parseJsonVideoItem(videoItem.get_object().value()));
    }

    return data;
}
/********************    JSON parser end    ********************/

QtPromise::QPromise<VideoSimpleData> getVideoSimpleData(const QString& api)
{
    return QtPromise::QPromise<VideoSimpleData>{[api](const QtPromise::QPromiseResolve<VideoSimpleData>& resolve, const QtPromise::QPromiseReject<VideoSimpleData>& reject) {
        QNetworkAccessManager* manager = new QNetworkAccessManager();
        QNetworkReply* reply           = manager->get(QNetworkRequest{api});
        QObject::connect(reply, &QNetworkReply::finished, [reply, resolve, reject]() {
            if (reply->error() == QNetworkReply::NoError) {
                const QString res = reply->readAll();
                const auto data   = parseJsonVideoSimpleData(res.toStdString());
                resolve(data);
            }
            else {
                reject();
            }
            reply->deleteLater();
        });
    }};
}

QtPromise::QPromise<VideoData> getVideoData(const QString& api, int type, int page, int ids)
{
    return QtPromise::QPromise<VideoData>{[&](const QtPromise::QPromiseResolve<VideoData>& resolve, const QtPromise::QPromiseReject<VideoData>& reject) {
        QNetworkAccessManager* manager = new QNetworkAccessManager();
        QString url                    = api + "?ac=videolist";
        if (ids != -1) {
            url += "&ids=" + QString::number(ids);
        }
        else {
            if (type != -1) {
                url += "&t=" + type;
            }
            if (page != 0) {
                url += "&pg=" + QString::number(page);
            }
        }
        QNetworkReply* reply = manager->get(QNetworkRequest{url});
        QObject::connect(reply, &QNetworkReply::finished, [reply, resolve, reject]() {
            if (reply->error() == QNetworkReply::NoError) {
                const QString res = reply->readAll();
                const auto data   = parserJsonVideoData(res.toStdString());
                resolve(data);
            }
            else {
                reject();
            }
            reply->deleteLater();
        });
    }};
}

#include "videoUtils.h"
#include "../networkManager/networkManager.h"
#include <QNetworkReply>
#include <QtConcurrent>
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
    std::regex url_pattern(R"(([^#$]+)\$(https?://[^#]+\.m3u8))");
    std::vector<std::string> parts;
    if (!separator.empty()) {
        std::string escaped_separator = std::regex_replace(separator, std::regex("\\$"), "\\$");
        std::regex sep_pattern(escaped_separator.empty() ? "(?!x)x" : escaped_separator);
        std::sregex_token_iterator iter(input.begin(), input.end(), sep_pattern, -1);
        std::sregex_token_iterator end;
        for (; iter != end; ++iter) {
            parts.push_back(*iter);
        }
    }
    else {
        parts.push_back(input);
    }

    for (const auto& part : parts) {
        auto matches_begin = std::sregex_iterator(part.begin(), part.end(), url_pattern);
        auto matches_end   = std::sregex_iterator();
        for (std::sregex_iterator i = matches_begin; i != matches_end; ++i) {
            std::smatch match = *i;
            if (match.size() == 3) {
                std::string episode = match[1].str();
                std::string url     = match[2].str();
                if (uniqueUrls.find(url) == uniqueUrls.end()) {
                    urls.push_back({episode, url});
                    uniqueUrls.insert(url);
                }
            }
        }
    }
    return urls;
}
VideoData parseJsonVideoData(const std::string& jsonContent)
{
    dom::parser parser;
    auto result = parser.parse(jsonContent);

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

/********************   XML parser start   ********************/
VideoSimpleItem parseXmlVideoSimpleItem(const pugi::xml_node& node)
{
    VideoSimpleItem item;
    item.vod_id    = node.child("id").text().as_int();
    item.vod_name  = node.child("name").text().as_string();
    item.type_id   = node.child("tid").text().as_int();
    item.type_name = node.child("type").text().as_string();
    item.vod_time  = node.child("last").text().as_string();
    return item;
}
VideoItem parseXmlVideoItem(const pugi::xml_node& node)
{
    VideoItem item;
    item.vod_id       = node.child("id").text().as_int();
    item.vod_name     = node.child("name").text().as_string();
    item.type_id      = node.child("tid").text().as_int();
    item.type_name    = node.child("type").text().as_string();
    item.vod_time     = node.child("last").text().as_string();
    item.vod_pic      = node.child("pic").text().as_string();
    item.vod_lang     = node.child("lang").text().as_string();
    item.vod_area     = node.child("area").text().as_string();
    item.vod_year     = node.child("year").text().as_string();
    item.vod_state    = node.child("state").text().as_string();
    item.vod_actor    = node.child("actor").text().as_string();
    item.vod_director = node.child("director").text().as_string();
    const auto urls   = node.child("dl");
    item.vod_play_url = parseXmlVideoUrls(urls);
    return item;
}
VideoClassType parseXmlVideoClassType(const pugi::xml_node& node)
{
    VideoClassType item;
    item.type_id   = node.attribute("id").as_int();
    item.type_name = node.text().get();
    return item;
}
std::vector<VideoUrls> parseXmlVideoUrls(const pugi::xml_node& node)
{
    std::vector<VideoUrls> list;
    const auto dds = node.children("dd");
    for (auto d : dds) {
        VideoUrls v;
        const auto item = d.text().as_string();
        std::string text(item);
        const std::string::size_type separator_pos = text.find('$');
        if (separator_pos != std::string::npos) {
            const std::string name = text.substr(0, separator_pos);
            const std::string url  = text.substr(separator_pos + 1);
            v.episode              = name;
            v.url                  = url;
        }
        list.push_back(v);
    }
    return list;
}
void parseXmlVideoBase(VideoBase& base, const pugi::xml_document& doc)
{
    base.code = 1;
    base.msg  = "success";

    if (const pugi::xml_node list = doc.child("rss").child("list")) {
        base.page      = list.attribute("page").as_int();
        base.pagecount = list.attribute("pagecount").as_int();
        base.limit     = list.attribute("pagesize").as_int();
        base.total     = list.attribute("recordcount").as_int();
    }
}
VideoSimpleData parseXmlVideoSimpleData(const std::string& xmlContent)
{
    VideoSimpleData data;
    pugi::xml_document doc;
    doc.load_string(xmlContent.c_str());
    parseXmlVideoBase(data, doc);

    const auto list = doc.child("rss").child("list");
    for (auto video : list.children("video")) {
        const auto item = parseXmlVideoSimpleItem(video);
        data.videoList.push_back(item);
    }

    const auto _class = doc.child("rss").child("class");
    for (auto ty : _class.children("ty")) {
        const auto item = parseXmlVideoClassType(ty);
        data.classList.push_back(item);
    }

    return data;
}
VideoData parseXmlVideoData(const std::string& xmlContent)
{
    VideoData data;
    pugi::xml_document doc;
    doc.load_string(xmlContent.c_str());
    parseXmlVideoBase(data, doc);

    const auto list = doc.child("rss").child("list");
    for (auto video : list.children("video")) {
        const auto item = parseXmlVideoItem(video);
        data.videoList.push_back(item);
    }

    return data;
}
/********************    XML parser end    ********************/

QtPromise::QPromise<VideoSimpleData> getVideoSimpleData(const QString& api)
{
    return QtPromise::QPromise<VideoSimpleData>{[api](const QtPromise::QPromiseResolve<VideoSimpleData>& resolve, const QtPromise::QPromiseReject<VideoSimpleData>& reject) {
        QNetworkAccessManager* manager = NetworkManager::instance().manager();
        QNetworkReply* reply           = manager->get(QNetworkRequest{api});
        QObject::connect(reply, &QNetworkReply::finished, [reply, resolve, reject]() {
            if (reply->error() == QNetworkReply::NoError) {
                const QString res = reply->readAll();
                // ReSharper disable once CppNoDiscardExpression
                QtConcurrent::run([res, resolve, reject]() {
                    try {
                        VideoSimpleData data;
                        if (res.startsWith("<?xml")) {
                            data = parseXmlVideoSimpleData(res.toStdString());
                        }
                        else {
                            data = parseJsonVideoSimpleData(res.toStdString());
                        }
                        QMetaObject::invokeMethod(QCoreApplication::instance(), [resolve, data]() {
                            resolve(data);
                        });
                    }
                    catch (...) {
                        QMetaObject::invokeMethod(QCoreApplication::instance(), reject);
                    }
                });
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
        QNetworkAccessManager* manager = NetworkManager::instance().manager();
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
                // ReSharper disable once CppNoDiscardExpression
                QtConcurrent::run([res, resolve, reject]() {
                    try {
                        VideoData data;
                        if (res.startsWith("<?xml")) {
                            data = parseXmlVideoData(res.toStdString());
                        }
                        else {
                            data = parseJsonVideoData(res.toStdString());
                        }
                        QMetaObject::invokeMethod(QCoreApplication::instance(), [resolve, data]() {
                            resolve(data);
                        });
                    }
                    catch (...) {
                        QMetaObject::invokeMethod(QCoreApplication::instance(), reject);
                    }
                });
            }
            else {
                reject();
            }
            reply->deleteLater();
        });
    }};
}

#ifndef VIDEOUTILS_H
#define VIDEOUTILS_H

#pragma once

#include "../../common/common.h"
#include <QtPromise>
#include "simdjson.h"

using namespace simdjson;

/********************   JSON parser start   ********************/
VideoSimpleItem parseJsonVideoSimpleItem(const dom::object& obj);
VideoItem parseJsonVideoItem(const dom::object& obj);
VideoClassType parseJsonVideoClassType(const dom::object& obj);
VideoSimpleData parseJsonVideoSimpleData(const std::string& jsonContent);
void parseJsonVideoBase(VideoBase& base, const dom::object& json);
std::vector<VideoUrls> parseJsonVideoUrls(const std::string& str);
VideoData parserJsonVideoData(const std::string& jsonContent);
/********************    JSON parser end    ********************/

QtPromise::QPromise<VideoSimpleData> getVideoSimpleData(const QString& api);

QtPromise::QPromise<VideoData> getVideoData(const QString& api, int type = -1, int page = 1, int ids = -1);

#endif // VIDEOUTILS_H
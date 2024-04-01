#ifndef VIDEOUTILS_H
#define VIDEOUTILS_H

#pragma once

#include "../../common/common.h"
#include <QtPromise>
#include "simdjson.h"
#include "pugixml.hpp"

using namespace simdjson;

/********************   JSON parser start   ********************/
VideoSimpleItem parseJsonVideoSimpleItem(const dom::object& obj);
VideoItem parseJsonVideoItem(const dom::object& obj);
VideoClassType parseJsonVideoClassType(const dom::object& obj);
std::vector<VideoUrls> parseJsonVideoUrls(const std::string& str, const std::string& separator);
void parseJsonVideoBase(VideoBase& base, const dom::object& json);
VideoSimpleData parseJsonVideoSimpleData(const std::string& jsonContent);
VideoData parserJsonVideoData(const std::string& jsonContent);
/********************    JSON parser end    ********************/

/********************   XML parser start   ********************/
VideoSimpleItem parseXmlVideoSimpleItem(const pugi::xml_node& node);
VideoItem parseXmlVideoItem(const pugi::xml_node& node);
VideoClassType parseXmlVideoClassType(const pugi::xml_node& node);
std::vector<VideoUrls> parseXmlVideoUrls(const std::string& str);
void parseXmlVideoBase(VideoBase& base, const std::string& content);
VideoSimpleData parserXmlVideoSimpleData(const std::string& xmlContent);
VideoData parserXmlVideoData(const std::string& xmlContent);
/********************    XML parser end    ********************/

VideoDataType checkApiDataType(const std::string& content);

QtPromise::QPromise<VideoSimpleData> getVideoSimpleData(const QString& api);

QtPromise::QPromise<VideoData> getVideoData(const QString& api, int type = -1, int page = 1, int ids = -1);

#endif // VIDEOUTILS_H
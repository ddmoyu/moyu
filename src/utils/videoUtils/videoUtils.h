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
VideoData parseJsonVideoData(const std::string& jsonContent);
/********************    JSON parser end    ********************/

/********************   XML parser start   ********************/
VideoSimpleItem parseXmlVideoSimpleItem(const pugi::xml_node& node);
VideoItem parseXmlVideoItem(const pugi::xml_node& node);
VideoClassType parseXmlVideoClassType(const pugi::xml_node& node);
std::vector<VideoUrls> parseXmlVideoUrls(const pugi::xml_node& node);
void parseXmlVideoBase(VideoBase& base, const pugi::xml_document& doc);
VideoSimpleData parseXmlVideoSimpleData(const std::string& xmlContent);
VideoData parseXmlVideoData(const std::string& xmlContent);
/********************    XML parser end    ********************/

QtPromise::QPromise<VideoSimpleData> getVideoSimpleData(const QString& api);

QtPromise::QPromise<VideoData> getVideoData(const QString& api, int type = -1, int page = 1, int ids = -1);

#endif // VIDEOUTILS_H
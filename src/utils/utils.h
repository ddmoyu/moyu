#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <QtPromise>
#include "../common/common.h"

QString invokeStyleSheetLoad(const QString& qValue);

VideoSimpleData getVideoSimpleData(const QString& api);

QtPromise::QPromise<QString> testPromise(const QUrl& api);

#endif // UTILS_H

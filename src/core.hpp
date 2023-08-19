#pragma once

#include <qobjectdefs.h>

QT_BEGIN_NAMESPACE
class QTranslator;
class QQmlApplicationEngine;
QT_END_NAMESPACE

class Core
{
public:
    Core();
    ~Core();

private:
    QTranslator *translator;
    QQmlApplicationEngine *engine;
};

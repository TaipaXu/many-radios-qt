#include "./util.hpp"
#include <QGuiApplication>
#include <QPalette>
#include <QLocale>

namespace Util
{
    bool isDarkThemeMode()
    {
        return QGuiApplication::palette().window().color().lightnessF() < 0.5;
    }

    bool isChineseLanguage()
    {
        return QLocale::system().name().startsWith("zh");
    }
} // namespace Util

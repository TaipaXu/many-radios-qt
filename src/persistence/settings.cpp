#include "./settings.hpp"
#include <QSettings>
#include "utils/util.hpp"

namespace Persistence
{
    Settings::Settings()
        : Persistence()
    {
        settings = new QSettings(getSettingsFilePath(), QSettings::IniFormat);
        readSettings();
    }

    Settings::~Settings()
    {
        writeSettings();
        settings->deleteLater();
    }

    Link::Theme::Mode Settings::getMode() const
    {
        return mode;
    }

    void Settings::setMode(Link::Theme::Mode mode)
    {
        this->mode = mode;
        settings->setValue("mode", static_cast<int>(mode));
    }

    const Link::Language::Type &Settings::getLanguage() const
    {
        return language;
    }

    void Settings::setLanguage(Link::Language::Type language)
    {
        this->language = language;
        settings->setValue("language", static_cast<int>(language));
    }

    QString Settings::getSettingsFilePath() const
    {
        const QString fileName = QString("%1.ini").arg("settings");
        const QString filePath = Persistence::getSettingsFilePath(fileName);

        return filePath;
    }

    void Settings::readSettings()
    {
        mode = static_cast<Link::Theme::Mode>(settings->value("mode", static_cast<int>(Util::isDarkThemeMode() ? Link::Theme::Mode::Dark : Link::Theme::Mode::Light)).toInt());
        language = static_cast<Link::Language::Type>(settings->value("language", Util::isChineseLanguage() ? 1 : 0).toInt());
    }

    void Settings::writeSettings()
    {
        settings->sync();
    }
} // namespace Persistence

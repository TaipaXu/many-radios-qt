#pragma once
#include "./persistence.hpp"
#include "links/theme.hpp"
#include "links/language.hpp"

QT_BEGIN_NAMESPACE
class QSettings;
QT_END_NAMESPACE

namespace Persistence
{
    class Settings : public Persistence
    {
    public:
        Settings();
        ~Settings();

        Link::Theme::Mode getMode() const;
        void setMode(Link::Theme::Mode mode);
        const Link::Language::Type &getLanguage() const;
        void setLanguage(Link::Language::Type language);

    private:
        QString getSettingsFilePath() const;
        void readSettings() override;
        void writeSettings() override;

    private:
        QSettings *settings;
        Link::Theme::Mode mode;
        Link::Language::Type language;
    };
} // namespace Persistence

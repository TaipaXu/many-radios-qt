#pragma once

#include <QObject>
#include <QColor>

namespace Persistence
{
    class Settings;
} // namespace Persistence

namespace Link
{
    class Theme : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(Mode mode READ getMode WRITE setMode NOTIFY changed)
        Q_PROPERTY(QColor alternateBase READ getAlternateBase NOTIFY changed)
        Q_PROPERTY(QColor base READ getBase NOTIFY changed)
        Q_PROPERTY(QColor brightText READ getBrightText NOTIFY changed)
        Q_PROPERTY(QColor button READ getButton NOTIFY changed)
        Q_PROPERTY(QColor buttonText READ getButtonText NOTIFY changed)
        Q_PROPERTY(QColor dark READ getDark NOTIFY changed)
        Q_PROPERTY(QColor highlight READ getHighlight NOTIFY changed)
        Q_PROPERTY(QColor highlightedText READ getHighlightedText NOTIFY changed)
        Q_PROPERTY(QColor light READ getLight NOTIFY changed)
        Q_PROPERTY(QColor link READ getLink NOTIFY changed)
        Q_PROPERTY(QColor linkVisited READ getLinkVisited NOTIFY changed)
        Q_PROPERTY(QColor mid READ getMid NOTIFY changed)
        Q_PROPERTY(QColor midlight READ getMidlight NOTIFY changed)
        Q_PROPERTY(QColor shadow READ getShadow NOTIFY changed)
        Q_PROPERTY(QColor text READ getText NOTIFY changed)
        Q_PROPERTY(QColor toolTipBase READ getToolTipBase NOTIFY changed)
        Q_PROPERTY(QColor toolTipText READ getToolTipText NOTIFY changed)
        Q_PROPERTY(QColor window READ getWindow NOTIFY changed)
        Q_PROPERTY(QColor windowText READ getWindowText NOTIFY changed)

    public:
        enum class Mode
        {
            Light,
            Dark
        };
        Q_ENUM(Mode)

    public:
        static Theme *getInstance();
        Theme(const Theme &) = delete;
        Theme &operator=(const Theme &) = delete;
        ~Theme();

        Mode getMode() const;
        void setMode(Mode mode);
        QColor getAlternateBase() const;
        QColor getBase() const;
        QColor getBrightText() const;
        QColor getButton() const;
        QColor getButtonText() const;
        QColor getDark() const;
        QColor getHighlight() const;
        QColor getHighlightedText() const;
        QColor getLight() const;
        QColor getLink() const;
        QColor getLinkVisited() const;
        QColor getMid() const;
        QColor getMidlight() const;
        QColor getShadow() const;
        QColor getText() const;
        QColor getToolTipBase() const;
        QColor getToolTipText() const;
        QColor getWindow() const;
        QColor getWindowText() const;

    signals:
        void changed();

    private:
        explicit Theme(QObject *parent = nullptr);

        Mode mode;
        Persistence::Settings *settingsPersistence;
    };
} // namespace Link

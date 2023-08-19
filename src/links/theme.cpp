#include "./theme.hpp"
#include "persistence/settings.hpp"

namespace Link
{
    Theme::Theme(QObject *parent)
        : QObject(parent)
    {
        settingsPersistence = new Persistence::Settings();
        mode = settingsPersistence->getMode();
    }

    Theme *Theme::getInstance()
    {
        static Theme instance;
        return &instance;
    }

    Theme::~Theme()
    {
        delete settingsPersistence;
    }

    Theme::Mode Theme::getMode() const
    {
        return mode;
    }

    void Theme::setMode(Mode mode)
    {
        if (this->mode == mode)
            return;

        this->mode = mode;
        emit changed();

        settingsPersistence->setMode(mode);
    }

    QColor Theme::getAlternateBase() const
    {
        return mode == Mode::Light ? QColor(255, 255, 255) : QColor(0, 0, 0);
    }

    QColor Theme::getBase() const
    {
        return mode == Mode::Light ? QColor(255, 255, 255) : QColor(0, 0, 0);
    }

    QColor Theme::getBrightText() const
    {
        return mode == Mode::Light ? QColor(0, 0, 0) : QColor(255, 255, 255);
    }

    QColor Theme::getButton() const
    {
        return mode == Mode::Light ? QColor(255, 255, 255) : QColor(0, 0, 0);
    }

    QColor Theme::getButtonText() const
    {
        return mode == Mode::Light ? QColor(0, 0, 0) : QColor(255, 255, 255);
    }

    QColor Theme::getDark() const
    {
        return mode == Mode::Light ? QColor(255, 0, 0) : QColor(255, 0, 0);
    }

    QColor Theme::getHighlight() const
    {
        return mode == Mode::Light ? QColor(255, 0, 0) : QColor(255, 0, 0);
    }

    QColor Theme::getHighlightedText() const
    {
        return mode == Mode::Light ? QColor(100, 100, 100) : QColor(200, 200, 200);
    }

    QColor Theme::getLight() const
    {
        return mode == Mode::Light ? QColor(255, 0, 0) : QColor(255, 0, 0);
    }

    QColor Theme::getLink() const
    {
        return mode == Mode::Light ? QColor(255, 0, 0) : QColor(255, 0, 0);
    }

    QColor Theme::getLinkVisited() const
    {
        return mode == Mode::Light ? QColor(255, 0, 0) : QColor(255, 0, 0);
    }

    QColor Theme::getMid() const
    {
        return mode == Mode::Light ? QColor(255, 0, 0) : QColor(255, 0, 0);
    }

    QColor Theme::getMidlight() const
    {
        return mode == Mode::Light ? QColor(255, 0, 0) : QColor(255, 0, 0);
    }

    QColor Theme::getShadow() const
    {
        return mode == Mode::Light ? QColor(0, 0, 0) : QColor(0, 0, 0);
    }

    QColor Theme::getText() const
    {
        return mode == Mode::Light ? QColor(0, 0, 0) : QColor(255, 255, 255);
    }

    QColor Theme::getToolTipBase() const
    {
        return mode == Mode::Light ? QColor(0, 0, 0) : QColor(0, 0, 0);
    }

    QColor Theme::getToolTipText() const
    {
        return mode == Mode::Light ? QColor(0, 0, 0) : QColor(0, 0, 0);
    }

    QColor Theme::getWindow() const
    {
        return mode == Mode::Light ? QColor(255, 255, 255) : QColor(0, 0, 0);
    }

    QColor Theme::getWindowText() const
    {
        return mode == Mode::Light ? QColor(0, 0, 0) : QColor(255, 255, 255);
    }
} // namespace Link

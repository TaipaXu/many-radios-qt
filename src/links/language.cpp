#include "language.hpp"
#include "persistence/settings.hpp"

namespace Link
{
    Language::Language(QObject *parent)
        : QObject(parent)
    {
        settingsPersistence = new Persistence::Settings();
        type = settingsPersistence->getLanguage();
    }

    Language *Language::getInstance()
    {
        static Language instance;
        return &instance;
    }

    Language::~Language()
    {
        delete settingsPersistence;
    }

    Language::Type Language::getType() const
    {
        return type;
    }

    void Language::setType(Type type)
    {
        if (this->type == type)
            return;

        this->type = type;
        emit changed(type);

        settingsPersistence->setLanguage(type);
    }
} // namespace Link

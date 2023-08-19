#pragma once

#include <array>
#include <QObject>
#include <QStringList>

namespace Persistence
{
    class Settings;
} // namespace Persistence

namespace Link
{
    class Language : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(Type type READ getType WRITE setType NOTIFY changed)

    public:
        enum class Type
        {
            En,
            Zh,
        };
        Q_ENUM(Type)

    public:
        static Language *getInstance();
        Language(const Language &) = delete;
        Language &operator=(const Language &) = delete;
        ~Language();

        Type getType() const;
        void setType(Type type);

    signals:
        void changed(Type type);

    private:
        explicit Language(QObject *parent = nullptr);

    private:
        Type type;
        Persistence::Settings *settingsPersistence;
    };
} // namespace Link

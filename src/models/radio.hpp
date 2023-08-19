#pragma once

#include <QString>

namespace Model
{
    class Radio
    {
    public:
        Radio(const QString &name, const QString &favicon, const QString &url);
        ~Radio() = default;

        const QString &getName() const;
        const QString &getFavicon() const;
        const QString &getUrl() const;

    private:
        const QString name;
        const QString favicon;
        const QString url;
    };
} // namespace Model

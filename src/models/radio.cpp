#include "./radio.hpp"

namespace Model
{
    Radio::Radio(const QString &name, const QString &favicon, const QString &url)
        : name{name}, favicon{favicon}, url{url}
    {
    }

    const QString &Radio::getName() const
    {
        return name;
    }

    const QString &Radio::getFavicon() const
    {
        return favicon;
    }

    const QString &Radio::getUrl() const
    {
        return url;
    }
} // namespace Model

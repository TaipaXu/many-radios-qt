#pragma once

#include <QObject>
#include "qmodels/radios.hpp"
#include "persistence/radio.hpp"

namespace Link
{
    class Favorites : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(QModel::Radios *radiosModel READ getRadiosModel CONSTANT)

    public:
        Favorites(const Favorites &) = delete;
        Favorites &operator=(const Favorites &) = delete;
        static Favorites *getInstance();
        ~Favorites();

        QModel::Radios *getRadiosModel() const;
        Q_INVOKABLE bool isFavorite(const QString &url) const;
        Q_INVOKABLE void addFavorite(const QString &name, const QString &favicon, const QString &url) const;
        Q_INVOKABLE void removeFavorite(const QString &url) const;

    private:
        explicit Favorites(QObject *parent = nullptr);

    private:
        QModel::Radios *radiosModel;
        Persistence::Radio *persistenceRadio;
    };
} // namespace Link

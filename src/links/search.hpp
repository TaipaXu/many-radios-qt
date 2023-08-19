#pragma once

#include <QObject>
#include "./radios.hpp"

namespace Model
{
    class Radio;
} // namespace Model

namespace Network
{
    class Search;
} // namespace Network

namespace Link
{
    class Search : public Radios
    {
        Q_OBJECT

        Q_PROPERTY(QStringList countries READ getCountryOptions NOTIFY foundCountries)
        Q_PROPERTY(QStringList languages READ getLanguageOptions NOTIFY foundLanguages)

    public:
        explicit Search(QObject *parent = nullptr);
        ~Search() = default;

        QStringList getCountryOptions() const;
        QStringList getLanguageOptions() const;
        Q_INVOKABLE void getCountries() const;
        Q_INVOKABLE void getLanguages() const;
        Q_INVOKABLE void getRadios(const QString &name, const QString &country, const QString &language);
        Q_INVOKABLE void getMoreRadios(const QString &name, const QString &country, const QString &language);

    signals:
        void foundCountries() const;
        void foundLanguages() const;

    private slots:
        void handleNetworkFoundCountries(QStringList &countries);
        void handleNetworkFoundLanguages(QStringList &languages);
        void handleNetworkFoundRadios(std::list<std::shared_ptr<Model::Radio>> &radios);

    private:
        QStringList countries;
        QStringList languages;
        Network::Search *searchNetwork;
    };
} // namespace Link

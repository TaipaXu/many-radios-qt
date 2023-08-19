#pragma once

#include <list>
#include <memory>
#include <QObject>

QT_BEGIN_NAMESPACE
class QNetworkReply;
QT_END_NAMESPACE

namespace Model
{
    class Radio;
} // namespace Model

namespace Network
{
    class Search : public QObject
    {
        Q_OBJECT

    public:
        explicit Search(QObject *parent = nullptr);
        ~Search() = default;

        void getCountries() const;
        void getLanguages() const;
        void getRadios(const QString &name, const QString &country, const QString &language, int offset = 0, int limit = 10) const;

    signals:
        void foundCountries(QStringList &countries) const;
        void foundLanguages(QStringList &languages) const;
        void foundRadios(std::list<std::shared_ptr<Model::Radio>> &radios) const;

    private slots:
        void handleCountriesReply(QNetworkReply *reply) const;
        void handleLanguagesReply(QNetworkReply *reply) const;
        void handleRadiosReply(QNetworkReply *reply) const;
    };
} // namespace Network

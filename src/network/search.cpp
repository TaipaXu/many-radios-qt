#include "./search.hpp"
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QUrlQuery>
#include "models/radio.hpp"

namespace Network
{
    Search::Search(QObject *parent)
        : QObject(parent)
    {
    }

    void Search::getCountries() const
    {
        QNetworkAccessManager *const manager = new QNetworkAccessManager();
        QUrl url("http://95.179.139.106/json/countries");
        QNetworkRequest request(url);
        manager->get(request);
        connect(manager, &QNetworkAccessManager::finished, this, &Search::handleCountriesReply);
    }

    void Search::getLanguages() const
    {
        QNetworkAccessManager *const manager = new QNetworkAccessManager();
        QUrl url("http://95.179.139.106/json/languages");
        QNetworkRequest request(url);
        manager->get(request);
        connect(manager, &QNetworkAccessManager::finished, this, &Search::handleLanguagesReply);
    }

    void Search::getRadios(const QString &name, const QString &country, const QString &language, int offset, int limit) const
    {
        QNetworkAccessManager *manager = new QNetworkAccessManager();
        QUrl url("http://95.179.139.106/json/stations/search");
        QUrlQuery query;
        if (!name.isEmpty())
        {
            query.addQueryItem("name", name);
        }
        if (!country.isEmpty())
        {
            query.addQueryItem("country", country);
        }
        if (!language.isEmpty())
        {
            query.addQueryItem("language", language);
        }
        query.addQueryItem("offset", QString::number(offset));
        query.addQueryItem("limit", QString::number(limit));
        url.setQuery(query);
        QNetworkRequest request(url);
        manager->get(request);
        connect(manager, &QNetworkAccessManager::finished, this, &Search::handleRadiosReply);
    }

    void Search::handleCountriesReply(QNetworkReply *reply) const
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QString answer = reply->readAll();
            QJsonParseError jsonError;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(answer.toUtf8(), &jsonError);
            if (jsonError.error == QJsonParseError::NoError)
            {
                QJsonArray jsonArray = jsonDoc.array();
                QStringList countries;
                for (int i = 0; i < jsonArray.size(); i++)
                {
                    QJsonObject jsonObject = jsonArray.at(i).toObject();
                    countries.append(jsonObject["name"].toString());
                }
                emit foundCountries(countries);
            }
        }
        else
        {
        }
        reply->deleteLater();

        QNetworkAccessManager *manager = qobject_cast<QNetworkAccessManager *>(sender());
        manager->deleteLater();
    }

    void Search::handleLanguagesReply(QNetworkReply *reply) const
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QString answer = reply->readAll();
            QJsonParseError jsonError;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(answer.toUtf8(), &jsonError);
            if (jsonError.error == QJsonParseError::NoError)
            {
                QJsonArray jsonArray = jsonDoc.array();
                QStringList languages;
                for (int i = 0; i < jsonArray.size(); i++)
                {
                    QJsonObject jsonObject = jsonArray.at(i).toObject();
                    languages.append(jsonObject["name"].toString());
                }
                emit foundLanguages(languages);
            }
        }
        else
        {
        }
        reply->deleteLater();

        QNetworkAccessManager *manager = qobject_cast<QNetworkAccessManager *>(sender());
        manager->deleteLater();
    }

    void Search::handleRadiosReply(QNetworkReply *reply) const
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QByteArray data = reply->readAll();
            QJsonParseError jsonError;
            QJsonDocument jsonDoc(QJsonDocument::fromJson(data, &jsonError));
            if (jsonError.error == QJsonParseError::NoError)
            {
                std::list<std::shared_ptr<Model::Radio>> radios;
                for (auto &&radioJson : jsonDoc.array())
                {
                    QJsonObject radioObject = radioJson.toObject();
                    const QString name = radioObject["name"].toString();
                    const QString favicon = radioObject["favicon"].toString();
                    const QString url = radioObject["url"].toString();
                    std::shared_ptr<Model::Radio> radio = std::make_shared<Model::Radio>(name, favicon, url);
                    radios.push_back(radio);
                }
                emit foundRadios(radios);
            }
        }
        else
        {
        }
        reply->deleteLater();

        QNetworkAccessManager *manager = qobject_cast<QNetworkAccessManager *>(sender());
        manager->deleteLater();
    }
} // namespace Network

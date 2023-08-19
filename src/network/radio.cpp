#include "./radio.hpp"
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QString>
#include "models/radio.hpp"

namespace Network
{
    Radio::Radio(QObject *parent)
        : QObject(parent)
    {
    }

    void Radio::getRadiosByType(Link::TopRadios::Type type, int offset, int limit) const
    {
        QString address{QStringLiteral("http://89.58.16.19/json/stations/%1")};
        switch (type)
        {
        case Link::TopRadios::ByClicks:
        {
            address = address.arg("topclick");
            break;
        }
        case Link::TopRadios::ByVotes:
        {
            address = address.arg("topvote");
            break;
        }
        case Link::TopRadios::ByRecentClick:
        {
            address = address.arg("lastclick");
            break;
        }
        case Link::TopRadios::ByRecentlyChange:
        {
            address = address.arg("lastchange");
            break;
        }
        }

        QNetworkAccessManager *manager = new QNetworkAccessManager();
        QUrl url(address);
        QUrlQuery query;
        query.addQueryItem("offset", QString::number(offset));
        query.addQueryItem("limit", QString::number(limit));
        url.setQuery(query);
        QNetworkRequest request(url);
        manager->get(request);
        connect(manager, &QNetworkAccessManager::finished, this, &Radio::handleRadiosReply);
    }

    void Radio::handleRadiosReply(QNetworkReply *reply) const
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

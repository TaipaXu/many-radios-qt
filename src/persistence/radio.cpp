#include "./radio.hpp"
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>

namespace Persistence
{
    Radio::Radio()
    {
        checkDataFile();
        readSettings();
    }

    Radio::~Radio()
    {
        writeSettings();
    }

    const std::list<std::shared_ptr<Model::Radio>> Radio::getRadios() const
    {
        return radios;
    }

    void Radio::addRadio(std::shared_ptr<Model::Radio> radio)
    {
        radios.push_back(radio);

        writeSettings();
    }

    void Radio::removeRadio(std::shared_ptr<Model::Radio> radio)
    {
        radios.remove(radio);
    }

    void Radio::removeRadio(const QString &url)
    {
        radios.remove_if([&url](const std::shared_ptr<Model::Radio> &radio) {
            return radio->getUrl() == url;
        });
    }

    QString Radio::getDataFilePath() const
    {
        const QString fileName = QString("%1.json").arg("favorites");
        const QString filePath = Persistence::getDataFilePath(fileName);

        return filePath;
    }

    void Radio::readSettings()
    {
        const QString filePath = getDataFilePath();
        QFile file(filePath);

        if (!file.open(QIODevice::ReadOnly))
        {
            return;
        }

        QByteArray data = file.readAll();
        QJsonParseError jsonError;
        QJsonDocument document(QJsonDocument::fromJson(data, &jsonError));
        if (!document.isNull() && jsonError.error == QJsonParseError::NoError)
        {
            std::list<std::shared_ptr<Model::Radio>> radios;
            const QJsonArray radiosArray = document.array();
            for (auto &&radioJson : radiosArray)
            {
                const QJsonObject radioObject = radioJson.toObject();
                const QString name = radioObject["name"].toString();
                const QString favicon = radioObject["favicon"].toString();
                const QString url = radioObject["url"].toString();
                radios.push_back(std::make_shared<Model::Radio>(name, favicon, url));
            }
            this->radios = radios;
        }

        file.close();
    }

    void Radio::writeSettings()
    {
        const QString filePath = getDataFilePath();
        QFile file(filePath);

        if (!file.open(QIODevice::WriteOnly))
        {
            return;
        }

        QJsonArray radiosArray;
        for (auto &&radio : radios)
        {
            QJsonObject radioObject;
            radioObject["name"] = radio->getName();
            radioObject["favicon"] = radio->getFavicon();
            radioObject["url"] = radio->getUrl();
            radiosArray.append(radioObject);
        }

        QJsonDocument document(radiosArray);
        file.write(document.toJson());

        file.close();
    }

    void Radio::checkDataFile() const
    {
        const QString dataDirPath = getDataDirPath();
        QDir dataDir(dataDirPath);
        if (!dataDir.exists())
        {
            dataDir.mkpath(dataDirPath);
        }

        const QString dataFilePath = getDataFilePath();
        QFile file(dataFilePath);
        if (!file.exists())
        {
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            file.write("{}");
            file.close();
        }
    }
} // namespace Persistence

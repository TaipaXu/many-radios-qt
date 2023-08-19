#include "./search.hpp"
#include "models/radio.hpp"
#include "network/search.hpp"

namespace Link
{
    Search::Search(QObject *parent)
        : Radios(parent)
    {
        searchNetwork = new Network::Search(this);
        connect(searchNetwork, &Network::Search::foundCountries, this, &Search::handleNetworkFoundCountries);
        connect(searchNetwork, &Network::Search::foundLanguages, this, &Search::handleNetworkFoundLanguages);
        connect(searchNetwork, &Network::Search::foundRadios, this, &Search::handleNetworkFoundRadios);
    }

    QStringList Search::getCountryOptions() const
    {
        return countries;
    }

    QStringList Search::getLanguageOptions() const
    {
        return languages;
    }

    void Search::getCountries() const
    {
        searchNetwork->getCountries();
    }

    void Search::getLanguages() const
    {
        searchNetwork->getLanguages();
    }

    void Search::getRadios(const QString &name, const QString &country, const QString &language)
    {
        isSearching = true;
        searchNetwork->getRadios(name, country, language, offset, limit);
    }

    void Search::getMoreRadios(const QString &name, const QString &country, const QString &language)
    {
        isSearching = true;
        offset += limit;
        searchNetwork->getRadios(name, country, language, offset, limit);
    }

    void Search::handleNetworkFoundCountries(QStringList &countries)
    {
        this->countries = QStringList({""}) + countries;
        emit foundCountries();
    }

    void Search::handleNetworkFoundLanguages(QStringList &languages)
    {
        this->languages = QStringList({""}) + languages;
        emit foundLanguages();
    }

    void Search::handleNetworkFoundRadios(std::list<std::shared_ptr<Model::Radio>> &radios)
    {
        if (offset == 0)
        {
            radiosModel->setRadios(radios);
        }
        else
        {
            radiosModel->addRadios(radios);
        }
        isSearching = false;
    }
} // namespace Link

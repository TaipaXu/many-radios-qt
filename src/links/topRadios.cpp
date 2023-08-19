#include "./topRadios.hpp"
#include "models/radio.hpp"
#include "network/radio.hpp"

namespace Link
{
    TopRadios::TopRadios(QObject *parent)
        : Radios(parent)
    {
        radioNetwork = new Network::Radio(this);
        connect(radioNetwork, &Network::Radio::foundRadios, this, &TopRadios::handleFoundRadios);
    }

    TopRadios::Type TopRadios::getType() const
    {
        return type;
    }

    void TopRadios::setType(Type type)
    {
        if (type == None || this->type == type)
        {
            return;
        }

        offset = 0;
        this->type = type;

        radiosModel->clearRadios();
        getRadios();
    }

    void TopRadios::setMaxRadiosCount(int maxRadiosCount) const
    {
        radiosModel->setMaxCount(maxRadiosCount);
    }

    void TopRadios::getRadios()
    {
        isSearching = true;
        radioNetwork->getRadiosByType(type, offset, limit);
    }

    void TopRadios::getMoreRadios()
    {
        offset += limit;
        getRadios();
    }

    void TopRadios::handleFoundRadios(const std::list<std::shared_ptr<Model::Radio>> &radios)
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

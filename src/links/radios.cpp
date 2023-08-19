#include "./radios.hpp"

namespace Link
{
    Radios::Radios(QObject *parent)
        : QObject(parent)
    {
        radiosModel = new QModel::Radios(this);
    }

    QModel::Radios *Radios::getRadiosModel() const
    {
        return radiosModel;
    }

    bool Radios::getIsSearching() const
    {
        return isSearching;
    }
} // namespace Link

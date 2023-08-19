#include "./radios.hpp"
#include "models/radio.hpp"

namespace QModel
{
    Radios::Radios(QObject *parent)
        : QAbstractListModel(parent)
    {
    }

    int Radios::rowCount(const QModelIndex &parent) const
    {
        if (maxCount < 0)
        {
            return radios.size();
        }
        else
        {
            return std::min(maxCount, static_cast<int>(radios.size()));
        }
    }

    QVariant Radios::data(const QModelIndex &index, int role) const
    {
        if (!index.isValid())
            return QVariant();

        if (index.row() >= radios.size())
            return QVariant();

        auto it = radios.begin();
        std::advance(it, index.row());

        switch (role)
        {
        case Name:
            return (*it)->getName();
        case Favicon:
            return (*it)->getFavicon();
        case Url:
            return (*it)->getUrl();
        default:
            return QVariant();
        }
    }

    QHash<int, QByteArray> Radios::roleNames() const
    {
        QHash<int, QByteArray> roles;
        roles[Name] = "name";
        roles[Favicon] = "favicon";
        roles[Url] = "url";
        return roles;
    }

    void Radios::setRadios(const std::list<std::shared_ptr<Model::Radio>> &radios)
    {
        beginResetModel();
        this->radios = radios;
        endResetModel();
    }

    void Radios::addRadios(const std::list<std::shared_ptr<Model::Radio>> &radios)
    {
        beginInsertRows(QModelIndex(), this->radios.size(), this->radios.size() + radios.size() - 1);
        this->radios.insert(this->radios.end(), radios.begin(), radios.end());
        endInsertRows();
    }

    void Radios::clearRadios()
    {
        beginResetModel();
        this->radios.clear();
        endResetModel();
    }

    void Radios::setMaxCount(int maxCount)
    {
        beginResetModel();
        this->maxCount = maxCount;
        endResetModel();
    }
} // namespace QModel

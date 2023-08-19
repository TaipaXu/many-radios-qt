#pragma once

#include <QObject>
#include "qmodels/radios.hpp"

namespace Link
{
    class Radios : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(QModel::Radios *radiosModel READ getRadiosModel CONSTANT)
        Q_PROPERTY(int offset MEMBER offset)
        Q_PROPERTY(int limit MEMBER limit)
        Q_PROPERTY(bool isSearching READ getIsSearching)

    public:
        explicit Radios(QObject *parent = nullptr);
        virtual ~Radios() = default;

        QModel::Radios *getRadiosModel() const;
        bool getIsSearching() const;

    protected:
        QModel::Radios *radiosModel;
        int offset = 0;
        int limit = 60;
        bool isSearching = false;
    };
} // namespace Link

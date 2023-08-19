#pragma once

#include <list>
#include <memory>
#include <QObject>
#include "links/topRadios.hpp"

QT_BEGIN_NAMESPACE
class QNetworkReply;
QT_END_NAMESPACE

namespace Model
{
    class Radio;
} // namespace Model

namespace Network
{
    class Radio : public QObject
    {
        Q_OBJECT

    public:
        explicit Radio(QObject *parent = nullptr);
        ~Radio() = default;

        void getRadiosByType(Link::TopRadios::Type type, int offset = 0, int limit = 10) const;

    signals:
        void foundRadios(const std::list<std::shared_ptr<Model::Radio>> &radios) const;

    private slots:
        void handleRadiosReply(QNetworkReply *reply) const;
    };
} // namespace Network

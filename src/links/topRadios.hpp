#pragma once

#include <QObject>
#include "./radios.hpp"

namespace Model
{
    class Radio;
} // namespace Model

namespace Network
{
    class Radio;
} // namespace Network

namespace Link
{
    class TopRadios : public Radios
    {
        Q_OBJECT

    public:
        enum Type
        {
            None,
            ByClicks,
            ByVotes,
            ByRecentClick,
            ByRecentlyChange
        };
        Q_ENUM(Type)

        Q_PROPERTY(Type type READ getType WRITE setType)

    public:
        explicit TopRadios(QObject *parent = nullptr);
        ~TopRadios() = default;

        Type getType() const;
        void setType(Type type);
        Q_INVOKABLE void setMaxRadiosCount(int maxRadiosCount) const;
        Q_INVOKABLE void getRadios();
        Q_INVOKABLE void getMoreRadios();

    private slots:
        void handleFoundRadios(const std::list<std::shared_ptr<Model::Radio>> &radios);

    private:
        Type type = None;
        Network::Radio *radioNetwork;
    };
} // namespace Link

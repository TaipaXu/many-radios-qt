#pragma once

#include <list>
#include <memory>
#include <QAbstractListModel>

namespace Model
{
    class Radio;
} // namespace Model

namespace QModel
{
    class Radios : public QAbstractListModel
    {
        Q_OBJECT

    public:
        enum Role
        {
            Name = Qt::UserRole + 1,
            Favicon,
            Url,
        };

    public:
        explicit Radios(QObject *parent = nullptr);
        ~Radios() = default;

        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QHash<int, QByteArray> roleNames() const override;

        void setRadios(const std::list<std::shared_ptr<Model::Radio>> &radios);
        void addRadios(const std::list<std::shared_ptr<Model::Radio>> &radios);
        void clearRadios();
        void setMaxCount(int maxCount);

    private:
        std::list<std::shared_ptr<Model::Radio>> radios;
        int maxCount = -1;
    };
} // namespace QModel

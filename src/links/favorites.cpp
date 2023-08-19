#include "./favorites.hpp"

namespace Link
{
    Favorites::Favorites(QObject *parent)
        : QObject(parent)
    {
        radiosModel = new QModel::Radios(this);
        persistenceRadio = new Persistence::Radio();

        const std::list<std::shared_ptr<Model::Radio>> radios = persistenceRadio->getRadios();
        radiosModel->setRadios(radios);
    }

    Favorites *Favorites::getInstance()
    {
        static Favorites instance;
        return &instance;
    }

    Favorites::~Favorites()
    {
        delete persistenceRadio;
    }

    QModel::Radios *Favorites::getRadiosModel() const
    {
        return radiosModel;
    }

    bool Favorites::isFavorite(const QString &url) const
    {
        const std::list<std::shared_ptr<Model::Radio>> radios = persistenceRadio->getRadios();
        return std::any_of(radios.begin(), radios.end(), [&url](const std::shared_ptr<Model::Radio> &radio) {
            return radio->getUrl() == url;
        });
    }

    void Favorites::addFavorite(const QString &name, const QString &favicon, const QString &url) const
    {
        const std::shared_ptr<Model::Radio> radio = std::make_shared<Model::Radio>(name, favicon, url);
        persistenceRadio->addRadio(radio);
        const std::list<std::shared_ptr<Model::Radio>> radios = persistenceRadio->getRadios();
        radiosModel->setRadios(radios);
    }

    void Favorites::removeFavorite(const QString &url) const
    {
        persistenceRadio->removeRadio(url);
        const std::list<std::shared_ptr<Model::Radio>> radios = persistenceRadio->getRadios();
        radiosModel->setRadios(radios);
    }
} // namespace Link

#pragma once

#include <list>
#include <memory>
#include "./persistence.hpp"
#include "models/radio.hpp"

namespace Persistence
{
    class Radio : public Persistence
    {
    public:
        Radio();
        ~Radio();

        const std::list<std::shared_ptr<Model::Radio>> getRadios() const;
        void addRadio(std::shared_ptr<Model::Radio> radio);
        void removeRadio(std::shared_ptr<Model::Radio> radio);
        void removeRadio(const QString &url);

    private:
        QString getDataFilePath() const;
        void readSettings() override;
        void writeSettings() override;
        void checkDataFile() const;

    private:
        std::list<std::shared_ptr<Model::Radio>> radios;
    };

} // namespace Persistence

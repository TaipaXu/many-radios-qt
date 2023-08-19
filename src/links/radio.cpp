#include "./radio.hpp"
#include <thread>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include <QDebug>

namespace Link
{
    Radio::Radio(QObject *parent)
        : QObject(parent)
    {
        player = new QMediaPlayer(this);

        QAudioOutput *audioOutput = new QAudioOutput();
        player->setAudioOutput(audioOutput);
    }

    Radio *Radio::getInstance()
    {
        static Radio instance;
        return &instance;
    }

    const QString &Radio::getName() const
    {
        return name;
    }

    const QString &Radio::getFavicon() const
    {
        return favicon;
    }

    const QString &Radio::getUrl() const
    {
        return url;
    }

    bool Radio::getIsPlaying() const
    {
        return isPlaying;
    }

    void Radio::start(const QString &name, const QString &favicon, const QString &url)
    {
        this->name = name;
        this->favicon = favicon;
        this->url = url;
        isPlaying = true;

        emit startRadio();
        emit isPlayingChanged();

        std::thread t([this, &url]() {
            player->setSource(QUrl(url));
            player->play();
        });
        t.detach();
    }

    void Radio::play()
    {
        isPlaying = true;
        player->play();
        emit isPlayingChanged();
    }

    void Radio::pause()
    {
        isPlaying = false;
        player->pause();
        emit isPlayingChanged();
    }

    void Radio::stop()
    {
        isPlaying = false;
        player->stop();
        emit isPlayingChanged();
        emit stopRadio();
    }
} // namespace Link

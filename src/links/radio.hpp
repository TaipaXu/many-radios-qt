#pragma once

#include <QObject>

QT_BEGIN_NAMESPACE
class QMediaPlayer;
QT_END_NAMESPACE

namespace Link
{
    class Favorites;

    class Radio : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(QString name READ getName NOTIFY startRadio)
        Q_PROPERTY(QString favicon READ getFavicon NOTIFY startRadio)
        Q_PROPERTY(QString url READ getUrl NOTIFY startRadio)
        Q_PROPERTY(bool isPlaying READ getIsPlaying NOTIFY isPlayingChanged)

    public:
        Radio(const Radio &) = delete;
        Radio &operator=(const Radio &) = delete;
        ~Radio() = default;
        static Radio *getInstance();

        const QString &getName() const;
        const QString &getFavicon() const;
        const QString &getUrl() const;
        bool getIsPlaying() const;
        Q_INVOKABLE void start(const QString &name, const QString &favicon, const QString &url);
        Q_INVOKABLE void play();
        Q_INVOKABLE void pause();
        Q_INVOKABLE void stop();

    signals:
        void startRadio();
        void stopRadio();
        void isPlayingChanged();

    private:
        explicit Radio(QObject *parent = nullptr);

    private:
        QMediaPlayer *player;
        QString name;
        QString favicon;
        QString url;
        bool isPlaying;
    };
} // namespace Link

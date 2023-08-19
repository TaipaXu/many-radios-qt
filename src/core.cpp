#include "./core.hpp"
#include <QGuiApplication>
#include <QTranslator>
#include <QQmlApplicationEngine>
#include "links/topRadios.hpp"
#include "links/search.hpp"
#include "links/favorites.hpp"
#include "links/radio.hpp"
#include "links/language.hpp"
#include "links/theme.hpp"

Core::Core()
{
    translator = new QTranslator();
    Link::Language *language = Link::Language::getInstance();
    if (language->getType() == Link::Language::Type::Zh)
    {
        translator->load(":/i18n/zh_CN");
    }
    qApp->installTranslator(translator);

    qmlRegisterType<Link::TopRadios>("topRadios", 1, 0, "TopRadios");
    qmlRegisterType<Link::Search>("search", 1, 0, "Search");
    qmlRegisterSingletonType<Link::Favorites>("favorites", 1, 0, "Favorites", [](QQmlEngine *, QJSEngine *) -> QObject * {
        return Link::Favorites::getInstance();
    });
    qmlRegisterSingletonType<Link::Radio>("radio", 1, 0, "Radio", [](QQmlEngine *, QJSEngine *) -> QObject * {
        return Link::Radio::getInstance();
    });
    qmlRegisterSingletonType<Link::Language>("language", 1, 0, "Language", [](QQmlEngine *, QJSEngine *) -> QObject * {
        return Link::Language::getInstance();
    });
    qmlRegisterSingletonType<Link::Theme>("theme", 1, 0, "Theme", [](QQmlEngine *, QJSEngine *) -> QObject * {
        return Link::Theme::getInstance();
    });

    engine = new QQmlApplicationEngine();
    engine->load("qrc:/widgets/MainWindow.qml");
    engine->retranslate();

    QObject::connect(Link::Language::getInstance(), &Link::Language::changed, [this](Link::Language::Type type) {
        switch (type)
        {
        case Link::Language::Type::En:
        {
            qApp->removeTranslator(translator);
            break;
        }

        case Link::Language::Type::Zh:
        {
            translator->load(":/i18n/zh_CN");
            qApp->installTranslator(translator);
            break;
        }
        }
        engine->retranslate();
    });
}

Core::~Core()
{
    engine->deleteLater();
    translator->deleteLater();
}

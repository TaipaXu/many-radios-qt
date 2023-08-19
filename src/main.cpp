#include <QGuiApplication>
#include <QIcon>
#include "core.hpp"
#include "appConfig.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setOrganizationDomain(ORGANIZATION_DOMAIN);
    app.setApplicationVersion(PROJECT_VERSION);
    app.setApplicationName(PROJECT_NAME);
    app.setApplicationDisplayName(DISPLAY_NAME);

    app.setWindowIcon(QIcon(":/images/radio"));

    Core core;

    const int result = app.exec();

    return result;
}

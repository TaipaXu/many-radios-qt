find_package(Qt6 REQUIRED COMPONENTS Core Quick QuickControls2 Network Multimedia LinguistTools)
find_package(Threads)

configure_file(./appConfig.hpp.in ./appConfig.hpp)

set(TS_FILES i18n/app_zh_CN.ts)
qt6_create_translation(TRANS_FILE ${CMAKE_CURRENT_SOURCE_DIR} ${TS_FILES})
configure_file(assets.qrc assets.qrc @ONLY)

set(TARGET many-radios)
set(SOURCES
        main.cpp
        core.hpp
        core.cpp

        links/topRadios.hpp
        links/topRadios.cpp
        links/search.hpp
        links/search.cpp
        links/favorites.hpp
        links/favorites.cpp
        links/radios.hpp
        links/radios.cpp
        links/radio.hpp
        links/radio.cpp
        links/language.cpp
        links/language.hpp
        links/theme.hpp
        links/theme.cpp

        models/radio.hpp
        models/radio.cpp

        qmodels/radios.hpp
        qmodels/radios.cpp

        network/radio.hpp
        network/radio.cpp
        network/search.hpp
        network/search.cpp

        persistence/persistence.hpp
        persistence/persistence.cpp
        persistence/settings.hpp
        persistence/settings.cpp
        persistence/radio.hpp
        persistence/radio.cpp

        utils/util.hpp
        utils/util.cpp

        assets.qrc

        ${TRANS_FILE}
)

add_executable(
    ${TARGET}
    ${SOURCES}
)

IF (WIN32)
    set_property(TARGET ${TARGET} PROPERTY WIN32_EXECUTABLE true)
ENDIF()

target_link_libraries(${TARGET} PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::QuickControls2
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Multimedia
    ${CMAKE_THREAD_LIBS_INIT})

qt_add_qml_module(${TARGET}
    URI qml
    NO_RESOURCE_TARGET_PATH
    QML_FILES
        "widgets/MainWindow.qml"
        "widgets/Navbar.qml"
        "widgets/NavButton.qml"
        "widgets/Radio.qml"
        "widgets/Favicon.qml"
        "widgets/Radios.qml"
        "widgets/TopRadios.qml"
        "widgets/SomeTopRadios.qml"
        "widgets/PlayControl.qml"
        "pages/Tops.qml"
        "pages/Search.qml"
        "pages/MyFavorites.qml"
        "pages/Settings.qml"
)

set(CPACK_PACKAGE_DESCRIPTION "Many radios")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Many radios")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})

if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Taipa Xu <taipaxu@gmail.com>")

    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt6core6 (>= 6.0), libqt6quick6 (>= 6.0), libqt6quickcontrols2-6 (>= 6.0), libqt6network6 (>= 6.0), libqt6multimedia6 (>= 6.0), libqt6core5compat6 (>= 6.0), libqt6svg6 (>= 6.0)")

    set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")

    install(TARGETS many-radios
        RUNTIME DESTINATION bin
    )

    install(DIRECTORY ${PROJECT_BINARY_DIR}/src/qml/
        DESTINATION share/many-radios/qml
    )

    install(FILES many-radios.png DESTINATION share/icons/hicolor/48x48/apps)

    install(FILES ./debian/many-radios.desktop DESTINATION share/applications)
endif()


include(CPack)

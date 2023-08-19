import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import topRadios as Link
import favorites as Link

Pane {
    implicitHeight: radios.height
    property alias type: topRadios.type

    Link.TopRadios {
        id: topRadios
    }

    Radios {
        id: radios
        model: topRadios.radiosModel
        contextMenu: Menu {
            MenuItem {
                text: qsTr("Add to favorites")

                onTriggered: {
                    Link.Favorites.addFavorite(radios.name, radios.favicon, radios.url)
                }
            }
        }
    }

    function setMaxRadiosCount(count) {
        topRadios.setMaxRadiosCount(count)
    }

    function tryToGetMoreRadios() {
        if (!topRadios.isSearching) {
            topRadios.getMoreRadios()
        }
    }
}

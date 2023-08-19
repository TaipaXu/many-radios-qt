import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../widgets"
import favorites as Link

Flickable {
    flickableDirection: Flickable.VerticalFlick
    contentHeight: contentItem.childrenRect.height
    ScrollBar.vertical: ScrollBar {}

    Pane {
        Layout.fillWidth: true
        width: parent.width

        ColumnLayout {
            width: parent.width
            spacing: 10

            Radios {
                id: radios
                model: Link.Favorites.radiosModel
                contextMenu: Menu {
                    MenuItem {
                        text: qsTr("Remove")

                        onTriggered: {
                            Link.Favorites.removeFavorite(radios.url)
                        }
                    }
                }
            }
        }
    }
}

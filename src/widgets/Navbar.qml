import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import radio as Link
import theme as Link

Rectangle {
    id: root
    color: Link.Theme.mode === Link.Theme.Mode.Light ? "#f8f8f8" : "#181818"

    enum Type {
        Tops,
        Search,
        MyFavorites,
        Settings
    }

    property int type: Navbar.Type.Tops

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        NavButton {
            width: parent.width
            tip: qsTr("Tops")
            image: "qrc:/images/top"
            active: root.type === Navbar.Type.Tops

            onClicked: {
                root.type = Navbar.Type.Tops
            }
        }

        NavButton {
            width: parent.width
            tip: qsTr("Search")
            image: "qrc:/images/search"
            active: root.type === Navbar.Type.Search

            onClicked: {
                root.type = Navbar.Type.Search
            }
        }

        NavButton {
            width: parent.width
            tip: qsTr("Favorites")
            image: "qrc:/images/collection"
            active: root.type === Navbar.Type.MyFavorites

            onClicked: {
                root.type = Navbar.Type.MyFavorites
            }
        }

        Item {
            Layout.fillHeight: true
        }

        NavButton {
            width: parent.width
            tip: qsTr("Settings")
            image: "qrc:/images/settings"
            active: root.type === Navbar.Type.Settings

            onClicked: {
                root.type = Navbar.Type.Settings
            }
        }

        Item {
            id: bottomPadding
            Layout.preferredHeight: 0

            Behavior on Layout.preferredHeight  {
                NumberAnimation {
                    duration: 300;
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }

    Connections {
        target: Link.Radio

        function onStartRadio() {
            bottomPadding.Layout.preferredHeight = 55
        }

        function onStopRadio() {
            bottomPadding.Layout.preferredHeight = 0
        }
    }
}

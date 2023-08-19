import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import favorites as Link
import radio as Link

Control {
    id: root
    property string name: ""
    property string favicon: ""
    property string url: ""
    property bool isPlaying: false
    property bool isFavorite: false

    background: Rectangle {
        anchors.fill: parent
        color: Qt.rgba(255, 255, 255, 0.2)
    }

    Favicon {
        id: favicon
        anchors {
            left: parent.left
            leftMargin: 10
            verticalCenter: parent.verticalCenter
        }
        width: height
        height: root.height * 0.8
        source: root.favicon
    }

    Label {
        anchors {
            left: favicon.right
            leftMargin: 10
            verticalCenter: parent.verticalCenter
        }
        text: root.name
        font.pixelSize: 13
    }

    Image {
        anchors {
            right: play.left
            verticalCenter: parent.verticalCenter
            rightMargin: 20
        }
        width: height
        height: root.height * 0.4
        source: root.isFavorite ? "qrc:/images/favorite" : "qrc:/images/unfavorite"
        fillMode: Image.PreserveAspectFit

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor

            onClicked: {
                if (root.isFavorite) {
                    Link.Favorites.removeFavorite(root.url)
                } else {
                    Link.Favorites.addFavorite(root.name, root.favicon, root.url)
                }
                root.isFavorite = !root.isFavorite
            }
        }
    }

    Image {
        id: play
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: height
        height: root.height * 0.8
        source: root.isPlaying ? "qrc:/images/pause" : "qrc:/images/play"
        fillMode: Image.PreserveAspectFit

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor

            onClicked: {
                if (root.isPlaying) {
                    Link.Radio.pause()
                } else {
                    Link.Radio.play()
                }
            }
        }
    }

    Image {
        anchors.left: play.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 20
        width: height
        height: root.height * 0.4
        source: "qrc:/images/stop"
        fillMode: Image.PreserveAspectFit

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor

            onClicked: {
                Link.Radio.stop()
            }
        }
    }

    onUrlChanged: {
        root.isFavorite = Link.Favorites.isFavorite(root.url)
    }

    Connections {
        target: Link.Radio

        function onStartRadio() {
            root.name = Link.Radio.name
            root.favicon = Link.Radio.favicon
            root.url = Link.Radio.url
        }

        function onIsPlayingChanged() {
            root.isPlaying = Link.Radio.isPlaying
        }
    }
}

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Flow {
    id: root
    Layout.fillWidth: true
    width: parent.width

    required property var model
    property var contextMenu
    property string name
    property string favicon
    property string url

    Repeater {
        model: root.model
        delegate: radio
    }

    Component {
        id: radio

        Radio {
            required property string name
            required property string favicon
            required property string url

            width:  (parent.width - 1) / Math.floor(parent.width / itemWidth)
            height: 180

            contextMenu: root.contextMenu

            onContextRequest: (name, favicon, url) => {
                root.name = name
                root.favicon = favicon
                root.url = url
            }
        }
    }
}

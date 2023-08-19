import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import radio as Link
import theme as Link

Item {
    id: root

    property var contextMenu

    signal contextRequest(string name, string favicon, string url)

    Rectangle {
        anchors.fill: parent
        anchors.margins: 5
        color: "#FFD321"
        radius: 8

        ColumnLayout {
            anchors.fill: parent

            Item {
                Layout.preferredHeight: 10
            }

            Favicon {
                Layout.preferredWidth: 100
                Layout.preferredHeight: 100
                Layout.alignment: Qt.AlignHCenter
                source: root.favicon
            }

            Item {
                Layout.preferredHeight: 2
            }

            Label {
                text: root.name
                Layout.fillWidth: true
                color: Link.Theme.text
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                maximumLineCount: 2
                wrapMode: Label.WordWrap
                elide: Text.ElideRight
            }

            Item {
                Layout.fillHeight: true
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            cursorShape: Qt.PointingHandCursor

            onClicked: {
                if (mouse.button == Qt.LeftButton) {
                    Link.Radio.start(root.name, root.favicon, root.url)
                } else if (mouse.button == Qt.RightButton) {
                    contextMenu?.popup()
                    if (contextMenu !== undefined) {
                        root.contextRequest(root.name, root.favicon, root.url)
                    }
                }
            }
        }
    }
}

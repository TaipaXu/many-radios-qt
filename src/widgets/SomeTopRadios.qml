import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import topRadios as Link

Item {
    id: root
    implicitHeight: layout.height

    property alias type: topRadios.type

    signal requestMore(int type)

    ColumnLayout {
        id: layout
        width: parent.width

        Item {
            height: 10
        }

        RowLayout {
            Layout.fillWidth: true

            Item {
                width: 10
            }

            Label {
                text: getLabel()
                font.pixelSize: 20
            }

            Item {
                Layout.fillWidth: true
            }

            Label {
                text: "..."
                font.pixelSize: 20

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor

                    onClicked: requestMore(root.type)
                }
            }

            Item {
                width: 10
            }
        }

        TopRadios {
            id: topRadios
            Layout.fillWidth: true
        }
    }


    function getLabel() {
        switch (root.type) {
        case Link.TopRadios.ByClicks:
            return qsTr("Radios by clicks")
        case Link.TopRadios.ByVotes:
            return qsTr("Radios by votes")
        case Link.TopRadios.ByRecentClick:
            return qsTr("Radios by recent click")
        case Link.TopRadios.ByRecentlyChange:
            return qsTr("Radios by recently change")
        }
    }

    function changeRadiosCount() {
        const maxRowCount = 3
        const maxRadiosCount = Math.floor(width / itemWidth) * maxRowCount
        topRadios.setMaxRadiosCount(maxRadiosCount)
    }

    onWidthChanged: changeRadiosCount()

    Component.onCompleted: changeRadiosCount()
}

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import topRadios as Link
import favorites as Link

ApplicationWindow {
    id: root
    title: qsTr("About")
    width: 500
    height: 350

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        Label {
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("Many Radios")
            font.pixelSize: 30
        }

        Image {
            source: "qrc:/images/radio"
            Layout.alignment: Qt.AlignHCenter
            Layout.preferredWidth: 200
            Layout.preferredHeight: 200
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("Version: " + PROJECT_VERSION)
            font.pixelSize: 20
        }

        Label {
            Layout.alignment: Qt.AlignHCenter
            text: qsTr("Homepage(Github)")
            font.pixelSize: 20

            MouseArea {
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor

                onClicked: {
                    Qt.openUrlExternally(PROJECT_DOMAIN);
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }
}

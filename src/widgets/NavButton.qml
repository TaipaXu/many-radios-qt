import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import theme as Link

Item {
    id: root
    height: width
    property string tip;
    property string image;
    property bool active: false
    property bool hover: false

    signal clicked

    Image {
        id: image
        anchors.centerIn: parent
        width: 30
        height: width
        fillMode: Image.PreserveAspectFit
        anchors.verticalCenter: parent.verticalCenter
        source: root.image
    }

    ColorOverlay{
        anchors.fill: image
        source: image
        color: Link.Theme.mode === Link.Theme.Mode.Light ? (hover || active ? "#aaaaaa" : "#000000") : (hover || active ? "#aaaaaa" : "#FFFFFF")
    }

    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onEntered: {
            hover = true
        }

        onExited: {
            hover = false
        }

        onClicked: (mouse) => {
            if (mouse.button === Qt.LeftButton) {
                root.clicked()
            }
        }
    }
}

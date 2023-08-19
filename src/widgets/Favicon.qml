import QtQuick

Image {
    id: image
    source: source ?? "qrc:/images/radio"
    fillMode: Image.PreserveAspectFit

    Image {
        anchors.fill: parent
        source: "qrc:/images/radio"
        fillMode: Image.PreserveAspectFit
        visible: parent.status != Image.Ready
    }
}

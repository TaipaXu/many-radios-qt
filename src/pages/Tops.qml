import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../widgets"
import topRadios as Link

Item {
    StackLayout {
        id: stackLayout
        anchors.fill: parent
        currentIndex: 0

        Flickable {
            flickableDirection: Flickable.VerticalFlick
            contentHeight: contentItem.childrenRect.height
            ScrollBar.vertical: ScrollBar {}

            ColumnLayout {
                width: parent.width
                spacing: 20

                SomeTopRadios {
                    Layout.fillWidth: true
                    type: Link.TopRadios.ByClicks

                    onRequestMore: handleRequestMore(type)
                }

                SomeTopRadios {
                    Layout.fillWidth: true
                    type: Link.TopRadios.ByVotes

                    onRequestMore: handleRequestMore(type)
                }

                SomeTopRadios {
                    Layout.fillWidth: true
                    type: Link.TopRadios.ByRecentClick

                    onRequestMore: handleRequestMore(type)
                }

                SomeTopRadios {
                    Layout.fillWidth: true
                    type: Link.TopRadios.ByRecentlyChange

                    onRequestMore: handleRequestMore(type)
                }

                Item {
                    height: 60
                }
            }
        }

        ColumnLayout {
            Pane {
                id: header
                Layout.fillWidth: true
                height: 50
                z: 10

                RowLayout {
                    anchors.fill: parent

                    Image {
                        Layout.preferredWidth: 30
                        Layout.preferredHeight: 30
                        source: "qrc:/images/back"
                        fillMode: Image.PreserveAspectFit

                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor

                            onClicked: goBack()
                        }
                    }
                }
            }

            Flickable {
                id: topRadios
                Layout.fillWidth: true
                Layout.fillHeight: true
                flickableDirection: Flickable.VerticalFlick
                contentHeight: contentItem.childrenRect.height
                ScrollBar.vertical: ScrollBar {}

                ColumnLayout {
                    Layout.fillWidth: true
                    width: parent.width

                    Loader {
                        id: radiosLoader
                        anchors.fill: parent
                        active: false

                        sourceComponent: Component {
                            TopRadios {}
                        }
                    }

                    Item {
                        height: 60
                    }
                }

                onFlickEnded: {
                    if (topRadios.contentY + topRadios.height >= topRadios.contentHeight) {
                        radiosLoader.item.tryToGetMoreRadios()
                    }
                }
            }
        }

    }

    function handleRequestMore(type) {
        radiosLoader.active = true
        radiosLoader.item.type = type
        stackLayout.currentIndex = 1
    }

    function goBack() {
        stackLayout.currentIndex = 0
        radiosLoader.active = false
    }
}

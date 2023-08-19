import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../pages"
import radio as Link
import theme as Link

ApplicationWindow {
    id: root
    title: qsTr("Many Radios")
    width: 1000
    height: 700
    minimumWidth: 400
    minimumHeight: 300
    visible: true

    property int itemWidth: 130

    palette {
        alternateBase: Link.Theme.alternateBase
        base: Link.Theme.base
        brightText: Link.Theme.brightText
        button: Link.Theme.button
        buttonText: Link.Theme.buttonText
        text: Link.Theme.text
        window: Link.Theme.window
        windowText: Link.Theme.windowText
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        Navbar {
            id: navbar
            Layout.fillHeight: true
            width: 48
        }

        StackLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            currentIndex: navbar.type

            Tops {}

            Search {}

            MyFavorites {}

            Settings {}
        }
    }

    PlayControl {
        id: playControl
        width: parent.width
        height: 60
        anchors.bottom: parent.bottom
        z: 10
        state: "HIDE"

        states: [
            State {
                name: "SHOW"

                PropertyChanges {
                    target: playControl
                    anchors.bottomMargin: 0
                }
            },
            State {
                name: "HIDE"

                PropertyChanges {
                    target: playControl
                    anchors.bottomMargin: - playControl.height
                }
            }
        ]

        transitions: [
            Transition {
                from: "*"
                to: "SHOW"

                SequentialAnimation {
                    PropertyAnimation {
                        target: playControl
                        property: "anchors.bottomMargin"
                        duration: 300
                        easing.type: Easing.InOutQuad
                    }
                }
            },
            Transition {
                from: "*"
                to: "HIDE"

                SequentialAnimation {
                    PropertyAnimation {
                        target: playControl
                        property: "anchors.bottomMargin"
                        duration: 300
                        easing.type: Easing.InOutQuad
                    }
                }
            }
        ]
    }

    Connections {
        target: Link.Radio

        function onStartRadio() {
            if (playControl.state !== "SHOW") {
                playControl.state = "SHOW"
            }
        }

        function onStopRadio() {
            if (playControl.state !== "HIDE") {
                playControl.state = "HIDE"
            }
        }
    }
}

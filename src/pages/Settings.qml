import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import theme as Link
import language as Link

Flickable {
    flickableDirection: Flickable.VerticalFlick
    contentHeight: contentItem.childrenRect.height
    ScrollBar.vertical: ScrollBar {}

    Pane {
        width: parent.width

        ColumnLayout {
            width: parent.width
            spacing: 10

            RowLayout {
                Layout.fillWidth: true
                spacing: 10

                Label {
                    width: 60
                    text: qsTr("Theme")
                }

                Item {
                    Layout.fillWidth: true
                }

                ComboBox {
                    id: themeComboBox
                    model: ListModel {
                        ListElement { text: qsTr("Light Mode") }
                        ListElement { text: qsTr("Dark Mode") }
                    }

                    onActivated: {
                        switch (index) {
                        case 0:
                            Link.Theme.mode = Link.Theme.Mode.Light
                            break
                        case 1:
                            Link.Theme.mode = Link.Theme.Mode.Dark
                            break
                        }
                    }
                }
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: 10

                Label {
                    width: 60
                    text: qsTr("Language")
                }

                Item {
                    Layout.fillWidth: true
                }

                ComboBox {
                    id: languageComboBox
                    model: ListModel {
                        ListElement { text: "English" }
                        ListElement { text: "中文" }
                    }

                    onActivated: {
                        switch (index) {
                        case 0:
                            Link.Language.type = Link.Language.En
                            break
                        case 1:
                            Link.Language.type = Link.Language.Zh
                            break
                        }
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        switch (Link.Theme.mode) {
        case Link.Theme.Mode.Light:
            themeComboBox.currentIndex = 0
            break
        case Link.Theme.Mode.Dark:
            themeComboBox.currentIndex = 1
            break
        }

        switch (Link.Language.type) {
        case Link.Language.En:
            languageComboBox.currentIndex = 0
            break
        case Link.Language.Zh:
            languageComboBox.currentIndex = 1
            break
        }
    }
}

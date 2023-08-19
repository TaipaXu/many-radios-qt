import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../widgets"
import search as Link

Flickable {
    id: root
    flickableDirection: Flickable.VerticalFlick
    contentHeight: contentItem.childrenRect.height
    ScrollBar.vertical: ScrollBar {}

    Link.Search {
        id: search
    }

    Pane {
        width: parent.width

        ColumnLayout {
            width: parent.width
            spacing: 10

            Row {
                Layout.fillWidth: true
                spacing: 10

                Label {
                    id: nameLabel
                    width: 60
                    text: qsTr("Name")
                }

                TextField {
                    id: nameInput
                    width: parent.width - nameLabel.width - 10
                }
            }

            Row {
                Layout.fillWidth: true
                spacing: 10

                Label {
                    id: countryLabel
                    width: 60
                    text: qsTr("Country")
                }

                ComboBox {
                    id: countrySelector
                    width: parent.width - countryLabel.width - 10
                    model: search.countries
                }
            }

            Row {
                Layout.fillWidth: true
                spacing: 10

                Label {
                    id: languageLabel
                    width: 60
                    text: qsTr("Language")
                }

                ComboBox {
                    id: languageSelector
                    width: parent.width - languageLabel.width - 10
                    model: search.languages
                }
            }

            Button {
                text: qsTr("Search")
                Layout.alignment: Qt.AlignRight

                onClicked: {
                    search.getRadios(nameInput.text, countrySelector.currentText, languageSelector.currentText)
                }
            }

            Radios {
                id: radios
                model: search.radiosModel
                contextMenu: Menu {
                    MenuItem {
                        text: qsTr("Add to favorites")

                        onTriggered: {
                            Link.Favorites.addFavorite(radios.name, radios.favicon, radios.url)
                        }
                    }
                }
            }
        }
    }

    onFlickEnded: {
        if(root.contentY + root.height >= root.contentHeight && !search.isSearching) {
            search.getMoreRadios(nameInput.text, countrySelector.currentText, languageSelector.currentText)
        }
    }

    Component.onCompleted: {
        search.getCountries()
        search.getLanguages()
    }
}

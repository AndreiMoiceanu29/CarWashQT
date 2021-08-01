import QtQuick 2.4
import QtQuick.Controls 2.15

Item {
    property color normalColor: "#2e856e"
    property color hoverColor: "#b8d5cd"
    property color selectedColor: "#dfeae2"
    Rectangle {
        id: pageBg
        width: 640
        height: 480
        color: "#5ca08e"

        Column {
            id: column
            anchors.fill: parent
            anchors.topMargin: 107
            spacing: 40

            Row {
                id: row
                x: 25
                width: 200
                height: 50
                spacing: 25

                Button {
                    id: button
                    text: qsTr("Add CarWash")
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: button.down ? hoverColor : normalColor
                    }
                }

                Button {
                    id: button1
                    text: qsTr("Update CarWash")
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: button1.down ? hoverColor : normalColor
                    }
                }

                Button {
                    id: button2
                    text: qsTr("Delete CarWash")
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: button2.down ? hoverColor : normalColor
                    }
                }
            }

            ListView {
                id: listView
                width: parent.width
                height: 160
                ScrollBar.vertical: ScrollBar {
                    active: true
                    anchors.right: parent.right
                }
                anchors.horizontalCenter: parent.horizontalCenter
                model: ListModel {

                    ListElement {
                        name: "Self Mioveni"
                        carWashId: "2"
                        carWashOwner: "Moiceanu Andrei"
                    }
                    ListElement {
                        name: "Self Mioveni"
                        carWashId: "2"
                        carWashOwner: "Moiceanu Andrei"
                    }
                    ListElement {
                        name: "Self Mioveni"
                        carWashId: "2"
                        carWashOwner: "Moiceanu Andrei"
                    }
                    ListElement {
                        name: "Self Mioveni"
                        carWashId: "2"
                        carWashOwner: "Moiceanu Andrei"
                    }
                    ListElement {
                        name: "Self Mioveni"
                        carWashId: "2"
                        carWashOwner: "Moiceanu Andrei"
                    }
                    ListElement {
                        name: "Self Mioveni"
                        carWashId: "2"
                        carWashOwner: "Moiceanu Andrei"
                    }
                }
                delegate: Item {
                    x: 5
                    width: 80
                    height: 40
                    Row {
                        id: row1
                        spacing: 10

                        Text {
                            text: name
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                        }
                        Text {
                            text: carWashId
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                        }
                        Text {
                            text: carWashOwner
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                        }
                    }
                }
            }
        }
    }
}

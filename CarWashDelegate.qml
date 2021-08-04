import QtQuick 2.0

Item {
    property string name: ""
    property string owner: ""
    property string carWashId: ""
    property var carIds: ""
                    x: 5
                    width: parent.width
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
                            text: owner
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                        }
                        Text {
                            text: carIds.toString()
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                        }
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: listView.currentIndex = index
                    }
                }

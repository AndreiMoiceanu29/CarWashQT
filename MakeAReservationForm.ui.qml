import QtQuick 2.4
import QtQuick.Controls 2.12

Item {
    width: 400
    height: 400

    property color normalColor: "#2e856e"
    property color hoverColor: "#b8d5cd"
    property color selectedColor: "#dfeae2"
    Rectangle {
        id: pageBg
        width: 640
        height: 480
        color: "#5ca08e"

        Column {
            Text{
                text: "Make A Reservation"
                font.bold: true
                font.pointSize: 25
            }

            spacing: 10
            anchors.centerIn: parent
            Label {
                id: carLbl
                text: "Enter Car's ID"
            }
            TextField {
                id: carTxt
                placeholderText: "Car ID"
            }

            Label {
                id: carWashLbl
                text: "Enter Car Wash's ID"
            }
            TextField {
                id: carWashTxt
                placeholderText: "CarWash ID"
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                Rectangle {
                    anchors.fill: parent
                    color: normalColor
                    Text {

                        text: "Reserve"
                        anchors.centerIn: parent
                        font.bold: true
                    }
                }
            }
        }
    }
}

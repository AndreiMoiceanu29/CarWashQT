import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
Item {
    property color normalColor: "#2e856e"
    property color hoverColor: "#b8d5cd"
    property color selectedColor: "#dfeae2"
    property color textColor: "white"
    property alias colWidth: column.width
    property alias carBtn: carsMouseArea
    property alias carWashBtn: carWashesMouseArea
    property alias makeReservationsBtn: reservationsMouseArea
    //width: parent.width
    //height: parent.height

        Column {
            id: column
            height: parent.height
            width: 200


            Rectangle {
                id: rect1
                width: 200
                height: 50
                color: normalColor
                border.color: "#006a4e"
                border.width: 1
                Label{
                    text: "Cars"
                    color: textColor
                    font.pointSize: 20
                    font.bold: true

                    anchors.centerIn: parent

                }
                MouseArea{
                    id: carsMouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: rect1.color = hoverColor
                    onExited: rect1.color = normalColor
                    onClicked: {rect1.color = selectedColor}
                }
            }
            Rectangle {
                id: rect2
                width: 200
                height: 50
                color: normalColor
                border.color: "#006a4e"
                border.width: 1
                Label{
                    text: "Car Washes"
                    color: textColor
                    font.pointSize: 20
                    font.bold: true
                    anchors.centerIn: parent
                }
                MouseArea{
                    id: carWashesMouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: rect2.color = hoverColor
                    onExited: rect2.color = normalColor
                    onClicked: {rect2.color = selectedColor}
                }
            }
            Rectangle {
                id: rect3
                width: 200
                height: 50
                color: normalColor
                border.color: "#006a4e"
                border.width: 1
                Label{
                    text: "Make a Reservation"
                    font.bold: true
                    font.pointSize: 12
                    color: textColor
                    anchors.centerIn: parent
                }
                MouseArea{
                    id: reservationsMouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: rect3.color = hoverColor
                    onExited: rect3.color = normalColor
                    onClicked: {rect3.color = selectedColor}
                }
            }
            Rectangle{
                width: 200
                height: parent.height - 150
                color: "#2e856e"
                border.color: "#006a4e"
                border.width: 1

            }
        }





}

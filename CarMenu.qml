import QtQuick 2.4
import QtQuick.Controls 2.15
import com.mge.service 1.0
import com.mge.car 1.0
import "objectHandler.js" as ObjectHandler

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
                spacing: 25
                id: sortRow
                Button {
                    id: sortByNameBtn
                    text: "Sort By Name"
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: sortByNameBtn.down ? hoverColor : normalColor
                    }
                }

                Button {
                    id: sortByOwnerBtn
                    text: "Sort By Owner"
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: sortByOwnerBtn.down ? hoverColor : normalColor
                    }
                }
                Button {
                    id: sortByPlateBtn
                    text: "Sort by plate number"
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: sortByPlateBtn.down ? hoverColor : normalColor
                    }
                }
            }

            Row {
                id: filtersRow
                spacing: 10
                TextField {
                    id: carNameFilterTxt
                    placeholderText: "Car Name"
                }

                TextField {
                    id: carOwnerFilterTxt
                    placeholderText: "Car Owner"
                }
                TextField {
                    id: carPlateNumberFilterTxt
                    placeholderText: "Car Plate Number"
                }

            }

            Row {
                id: row
                x: 25
                width: 200
                height: 50
                spacing: 25

                Button {
                    id: button
                    text: qsTr("Add Car")
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: button.down ? hoverColor : normalColor
                    }
                    onClicked: {
                        addCarMenu.show()

                    }
                }
                AddCar{
                    id: addCarMenu
                    onRequestAddCar: {

                        Service.createCar(carEntity);
                    }
                }

                Button {
                    id: button1
                    text: qsTr("Update Car")
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
                    text: qsTr("Delete Car")
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: button2.down ? hoverColor : normalColor
                    }
                }
                Button {
                    id: undoBtn
                    text: "Undo"
                    background: Rectangle{
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: undoBtn.down ? hoverColor : normalColor
                    }
                }
                Button {
                    id: redoBtn
                    text: "Redo"
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: redoBtn.down ? hoverColor: normalColor
                    }
                }
            }

            Connections {
                target:Service
                onLoadCars: {
                    console.log("Signal sent!")
                    console.log(Service.cars)
                    console.log(Service.cars[0].name)
                   // listView.model = Service.cars
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
                model: Service.cars

                delegate:Item{
                    width: parent.width
                    height: parent.height
                    required property int entityId
                    required property string name
                    required property string owner
                    required property string plateNumber
                             Column{
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                            Label{
                            id: carId
                            text: parent.parent.entityId
                            }
                            Label{
                            id: carName
                            text: parent.parent.name
                            }
                            Label{
                            id: carOwner
                            text: parent.parent.owner
                            }
                            Label{
                            id:carPlateNumber
                            text: parent.parent.plateNumber
                            }
                        }
                }
            }
            }
        }
    }


/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

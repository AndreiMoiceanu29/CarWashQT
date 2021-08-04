import QtQuick 2.15
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
                    property bool asc: false
                    text: "Sort By Name"
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: sortByNameBtn.down ? hoverColor : normalColor
                    }
                    onClicked: {
                        Service.sortByName(asc);
                        asc = !asc;
                    }
                }

                Button {
                    id: sortByOwnerBtn
                    property bool asc: false
                    text: "Sort By Owner"
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: sortByOwnerBtn.down ? hoverColor : normalColor
                    }
                    onClicked: {
                        Service.sortByOwner(asc);
                        asc = !asc
                    }
                }
                Button {
                    id: sortByPlateBtn
                    text: "Sort by plate number"
                    property bool asc: false
                    background: Rectangle {
                        width: parent.width
                        height: parent.height
                        anchors.fill: parent
                        radius: width / 3
                        color: sortByPlateBtn.down ? hoverColor : normalColor
                    }
                    onClicked: {
                        Service.sortByPlate(asc)
                        asc = !asc
                    }
                }
            }

            Row {
                id: filtersRow
                spacing: 10
                TextField {
                    id: carNameFilterTxt
                    placeholderText: "Car Name"
                    onTextChanged: Service.filter(carNameFilterTxt.text,carOwnerFilterTxt.text,carPlateNumberFilterTxt.text)
                }

                TextField {
                    id: carOwnerFilterTxt
                    placeholderText: "Car Owner"
                    onTextChanged: Service.filter(carNameFilterTxt.text,carOwnerFilterTxt.text,carPlateNumberFilterTxt.text)
                }
                TextField {
                    id: carPlateNumberFilterTxt
                    placeholderText: "Car Plate Number"
                    onTextChanged: Service.filter(carNameFilterTxt.text,carOwnerFilterTxt.text,carPlateNumberFilterTxt.text)
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
                        Service.filter(carNameFilterTxt.text,carOwnerFilterTxt.text,carPlateNumberFilterTxt.text)
                    }
                    onRequestUpdate: {
                        Service.updateCar(oldCar,carEntity);
                        Service.filter(carNameFilterTxt.text,carOwnerFilterTxt.text,carPlateNumberFilterTxt.text)
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
                    onClicked: {
                        addCarMenu.isUpdating = true;
                        addCarMenu.oldCar = Service.cars[listView.currentIndex];
                        addCarMenu.show()
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
                    onClicked: {
                        Service.deleteCar(Service.cars[listView.currentIndex].entityId);
                        Service.filter(carNameFilterTxt.text,carOwnerFilterTxt.text,carPlateNumberFilterTxt.text)
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

                    listView.model = Service.cars
                    listView.forceLayout();
                }
                onCarsFiltered: {
                    listView.model = Service.filteredCars
                    for(var i=0; i<Service.filteredCars.length;i++){
                        console.log(Service.filteredCars[i].name)
                    }

                    listView.forceLayout();
                }
            }

            ListView {
                id: listView
                width: 640
                height: 160
                ScrollBar.vertical: ScrollBar {
                    active: true
                    anchors.right: parent.right
                }
                anchors.horizontalCenter: parent.horizontalCenter
                //model: Service.cars | Service.filteredCars
                highlight: Rectangle {color: "lightgrey";radius:5;width:parent.width}

                delegate: CarDelegate{
                    carName: Service.filteredCars[index].name
                    carOwner: Service.filteredCars[index].owner
                    carPlateNumber: Service.filteredCars[index].plateNumber
                    carId: Service.filteredCars[index].entityId
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

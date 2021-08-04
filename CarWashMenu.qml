import QtQuick 2.4
import QtQuick.Controls 2.15
import com.mge.service 1.0
import com.mge.carwash 1.0

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
                    onClicked: addCarWash.show()
                }
                AddCarWash {
                    id: addCarWash
                    onRequestAdd: Service.createCarWash(carWashEntity);
                    onRequestUpdate: Service.updateCarWash(oldCarWash,carWashEntity);
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
                    onClicked: {
                        addCarWash.isUpdating = true
                        addCarWash.oldCarWash = Service.carWashes[listView.currentIndex];
                        addCarWash.show()
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
                    onClicked:  Service.deleteCarWash(Service.carWashes[listView.currentIndex].entityId)
                }
            }

            Connections {
                target: Service
                onLoadCarWashes: {
                    listView.model = Service.carWashes
                    listView.forceLayout()
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
                highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
                anchors.horizontalCenter: parent.horizontalCenter
                model: Service.carWashes
                delegate: CarWashDelegate {
                    name: Service.carWashes[index].name
                    owner: Service.carWashes[index].owner
                    carWashId: Service.carWashes[index].entityId
                    carIds: Service.carWashes[index].carIds
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

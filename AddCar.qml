import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.0
import com.mge.car 1.0

Window {
    property color normalColor: "#2e856e"
    property color hoverColor: "#b8d5cd"
    property color selectedColor: "#dfeae2"
    width: 640
    height: 480
    //active: false
    id: addCarMenu
    signal requestAddCar(Car carEntity);
    Rectangle {
        id: pageBg
        width: 640
        height: 480
        color: "#5ca08e"
        Column {
            id: column
            spacing: 4
            anchors.centerIn: parent
            Text {

                text: "Add a car"
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
                font.pointSize: 25

            }
            Label {
                text: "Car Name"

            }
            TextField {
                id: carNameTxt
                placeholderText: "Name of car"
            }
            Label {
                text: "Car Owner"

            }
            TextField {
                id: carOwnerTxt
                placeholderText: "Owner of car"
            }
            Label {
                text: "Car Plate Number"

            }
            TextField {
                id: carPlateTxt
                placeholderText: "Plate number of car"
            }
            Label {
                text: "Car ID"

            }
            TextField {
                id: carIdTxt
                placeholderText: "ID of car"
            }

            Button {
                id: submitBtn
                anchors.horizontalCenter: parent.horizontalCenter

                    text: qsTr("Submit")
                background: Rectangle {
                    color: normalColor
                    radius: width/3
                    width: parent.width
                    height: parent.height
                    anchors.fill: parent


                }
                onClicked: {
                    //console.log(carNameTxt.text);
                    var carEntity = Qt.createQmlObject("import com.mge.car 1.0; Car {
                     entityId: parseInt(carIdTxt.text); name: carNameTxt.text; plateNumber: carPlateTxt.text; owner: carOwnerTxt.text
                    }",parent,"Car.h");
                    //console.log(carEntity.name);
                    requestAddCar(carEntity);
                    addCarMenu.close()
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

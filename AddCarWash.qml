import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import com.mge.carwash 1.0

Window {
    property color normalColor: "#2e856e"
    property color hoverColor: "#b8d5cd"
    property color selectedColor: "#dfeae2"
    property CarWash oldCarWash
    property bool isUpdating: false
    width: 640
    height: 480
    //active: false
    signal requestAdd(CarWash carWashEntity);
    signal requestUpdate(CarWash oldCarWash, CarWash carWashEntity);
    id: addCarMenu
    onClosing: {
        carWashNameTxt.text = ""
        carWashOwnerTxt.text = ""
        carWashIdTxt.text = isUpdating ? oldCarWash.entityId : ""
    }

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

                text: "Add a car wash"
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
                font.pointSize: 25

            }
            Label {
                text: "CarWash Name"

            }
            TextField {
                id: carWashNameTxt
                placeholderText: "Name of carwash"
            }
            Label {
                text: "CarWash Owner"

            }
            TextField {
                id: carWashOwnerTxt
                placeholderText: "Owner of carwash"
            }

            Label {
                text: "CarWash ID"

            }
            TextField {
                id: carWashIdTxt
                placeholderText: "ID of carwash"
                enabled: !isUpdating
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
                    var carWashEntity = Qt.createQmlObject("import com.mge.carwash 1.0; CarWash{
                    entityId: parseInt(carWashIdTxt.text); name: carWashNameTxt.text; owner: carWashOwnerTxt.text
                }",parent,"CarWash.h");
                    if(isUpdating)
                        requestUpdate(oldCarWash,carWashEntity);
                    else
                        requestAdd(carWashEntity);
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

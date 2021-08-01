import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

ApplicationWindow {
    id: window
    width: 700
    height: 480
    visible: true
    title: qsTr("Hello World")



    Row{
        id: row
        SideBar {
            id:sidebar
        width: 200
        height: parent.height
        carWashBtn.onClicked: {
            if(stackView.depth > 1){
                stackView.pop()
            }

            stackView.push("qrc:/CarWashMenuForm.ui.qml")

        }
        carBtn.onClicked: {
            if(stackView.depth > 1) {
                stackView.pop()
            }
            stackView.push("qrc:/CarMenu.qml")
        }
        makeReservationsBtn.onClicked: {
            if(stackView.depth > 1){
                stackView.pop()
            }
            stackView.push("qrc:/MakeAReservationForm.ui.qml")
        }
        }



        //CarMenu{}
        Rectangle {
            id: pageBg
            width: window.width - 200
            height: window.height
            color: "#5ca08e"

            StackView {
                id: stackView
                initialItem: "qrc:/CarMenu.qml"
                anchors.fill: parent
            }



        }
        anchors.fill: parent
        spacing: 0
        anchors.rightMargin: 0
    }





}

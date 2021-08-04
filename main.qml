import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.0

ApplicationWindow {
    id: window
    width: 1024
    height: 800
    visible: true
    title: qsTr("Hello World")



    Row{
        property bool logedIn: false
        LoginPanel{id: loginPanel}
        id: row
        SideBar {
            id:sidebar
        width: 200
        height: parent.height
        carWashBtn.enabled: row.logedIn
        carWashBtn.onClicked: {
            if(stackView.depth > 1){
                stackView.pop()
            }

            stackView.push("qrc:/CarWashMenu.qml")

        }
        carBtn.enabled: row.logedIn
        carBtn.onClicked: {
            if(stackView.depth > 1) {
                stackView.pop()
            }
            stackView.push("qrc:/CarMenu.qml")
        }
        makeReservationsBtn.enabled: row.logedIn
        makeReservationsBtn.onClicked: {
            if(stackView.depth > 1){
                stackView.pop()
            }
            stackView.push("qrc:/MakeAReservation.qml")
        }
        }



        //CarMenu{}
        RepositorySelection{
            id:repoSelection
            onFileChoosed: {
                console.log("File choosed")
                if(stackView.depth > 1) {
                    stackView.pop()
                }
                stackView.push("qrc:/CarMenu.qml")
            }
            onMemoryRepoChoosed: {
                console.log("File choosed")
                if(stackView.depth > 1) {
                    stackView.pop()
                }
                stackView.push("qrc:/CarMenu.qml")
            }
        }

        Rectangle {
            id: pageBg
            width: window.width - 200
            height: window.height
            color: "#5ca08e"

            StackView {
                id: stackView
                initialItem: "qrc:/LoginPanel.qml"
                anchors.fill: parent
            }





        }
        anchors.fill: parent
        spacing: 0
        anchors.rightMargin: 0
    }





}

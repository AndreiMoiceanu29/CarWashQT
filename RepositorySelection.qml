import QtQuick 2.4
import QtQuick.Controls 2.15
import QtQuick.Window 2.0
import QtQuick.Dialogs 1.0

Window {
    id: item1
    property color normalColor: "#2e856e"
    property color hoverColor: "#b8d5cd"
    property color selectedColor: "#dfeae2"
    width: 640
    height: 480
    signal fileChoosed(string carRepoFile , string carWashFileRepo)
    signal memoryRepoChoosed()
    Rectangle {
        id: pageBg
        width: 640
        height: 480
        color: "#5ca08e"

        Column {
            id: column
            x: 198
            y: 72
            width: 452
            height: 318
            anchors.verticalCenter: parent.verticalCenter
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                id: label
                text: qsTr("Choose Persistency Type")
                font.pointSize: 25
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }

            RadioButton {
                id: radioButton
                text: qsTr("Memory")
            }

            RadioButton {
                id: radioButton1
                text: qsTr("File System")
            }

            Button {
                id: button
                text: qsTr("Submit")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    if(radioButton1.checked){
                        fileSelectionPopup.open()
                    }else{
                        item1.memoryRepoChoosed()
                        item1.close()
                    }
                }
            }
        }
        Popup {
            id: fileSelectionPopup
            width: pageBg.width
            height: pageBg.height
            focus: true
            modal: true

            Column {
                Rectangle {
                    id: modalBg
                    width: 640
                    height: 480
                    color: "#5ca08e"
                    Column {
                        Label {
                            text: "Storage file selection"
                            font.bold: true
                            font.pointSize: 25
                        }

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        spacing: 10
                        Button {
                            id: carRepoBtn
                            text: "Car repo"
                            onClicked: carRepoFile.open()
                        }
                        FileDialog {
                            id: carRepoFile
                            title: "Please select a file for car repo"
                            onAccepted: {
                                console.log(carRepoFile.fileUrls)
                            }
                        }

                        Button {
                            id: carWashRepoBtn
                            text: "Car repo"
                            onClicked: carWashRepoFile.open()
                        }
                        FileDialog {
                            id: carWashRepoFile
                            title: "Please select a file for carwash repo"
                            onAccepted: {
                                console.log(carWashRepoFile.fileUrls)
                            }
                        }
                        Button {
                            text: "Submit"
                            anchors.horizontalCenter: parent.horizontalCenter
                            onClicked: {
                                if(carRepoFile.fileUrls && carWashRepoFile.fileUrls){
                                    fileSelectionPopup.close()
                                    item1.fileChoosed(carRepoFile.fileUrls,carWashRepoFile.fileUrls)
                                }
                            }
                        }
                    }
                }
            }
        }


    }
}

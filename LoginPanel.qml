import QtQuick 2.4
import QtQuick.Controls 2.15


Item {
    property color normalColor: "#2e856e"
    property color hoverColor: "#b8d5cd"
    property color selectedColor: "#dfeae2"
    //property bool logedIn: false
    id: loginPanel
    Rectangle {
        id: pageBg
        width: 640
        height: 480
        color: "#5ca08e"

        Column {
            id: column
            x: 154
            y: 60
            width: 468
            height: 278
            anchors.verticalCenter: parent.verticalCenter
            spacing: 15
            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                id: label
                text: qsTr("Username")
            }

            TextField {
                id: usernameTxt
                placeholderText: qsTr("User Name")
            }

            Label {
                id: label1
                text: qsTr("Password")
            }

            TextField {
                id: passwordTxt
                placeholderText: qsTr("Password")
                echoMode: TextInput.Password
            }

            Button {
                id: button
                text: qsTr("Login")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    if (usernameTxt.text === "admin" && passwordTxt.text === "admin"){
                        console.log("Login sucessfuly")
                        row.logedIn = true;
                        selectRepoType.show()


                    }else {
                        console.log("Wrong credentials !")
                    }
                }
                RepositorySelection {
                    id: selectRepoType
                }
            }
        }


    }
}

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Row{
        id: row
        SideBar {
            id:sidebar
        width: 200
        height: parent.height
        }


        //CarMenu{}
        Rectangle {
            id: pageBg
            width: 440
            height: 480
            color: "#5ca08e"


        }
        anchors.fill: parent
        anchors.rightMargin: 0
    }





}

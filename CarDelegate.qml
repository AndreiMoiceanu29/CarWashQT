import QtQuick 2.0

Item{
    property string carName: ""
    property string carOwner: ""
    property string carPlateNumber: ""
    property string carId: ""
                    width: parent.width
                    height: 40
                    Row {

                        width: parent.width
                        //height: parent.height
                        spacing: 10
                        Text {
                           // height: 20
                           // width: 50
                            text: carName
                        }
                        Text {
                          //  height: 20
                           // width: 50
                            text: carOwner
                        }
                        Text {
                          //  height: 20
                           // width: 50
                            text: carPlateNumber
                        }
                        Text {
                           // height: 20
                           // width: 50
                            text: carId
                        }

                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: listView.currentIndex = index
                    }
                }

import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.0

Rectangle {
    color: "blue"

    RowLayout {
        width: implicitWidth
        height: parent.height

        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            color: "white"

            verticalAlignment: Text.AlignVCenter

            renderType: Text.NativeRendering

            text: "Hello world!"
        }

        Button {
            text: "Woo"

            onClicked: Qt.quit()
        }

        TextField {
            width: 50
        }
    }
}

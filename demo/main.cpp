#include <QGuiApplication>
#include <QQuickView>
#include "layerview.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

	QtLayerShell::LayerView view(
			QtLayerShell::LayerView::layer_bottom,
			QString::fromUtf8("demo"));
	view.setAnchor(QtLayerShell::LayerView::anchor_bottom
			| QtLayerShell::LayerView::anchor_left
			| QtLayerShell::LayerView::anchor_right);
	view.setExclusiveZone(50);
	view.setMargin(0, 100, 0, 100);
	view.setKeyboardInteractivity(true);

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/hello.qml"));
	view.setHeight(50);
    view.show();

    return app.exec();
}

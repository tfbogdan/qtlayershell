#include <QGuiApplication>
#include <QQuickView>
#include <QtLayerShell/LayerView>
#include <stdint.h>

class DemoView : public QQuickView, public QtLayerShell::LayerView
{
public:
	DemoView(uint32_t layer, const QString layer_namespace)
		: QtLayerShell::LayerView(layer, layer_namespace)
	{
		setFlags(Qt::BypassWindowManagerHint | Qt::FramelessWindowHint);
	}
};


int main(int argc, char *argv[])
{
	qputenv("QT_QPA_PLATFORM", QByteArray("wayland"));
	qputenv("QT_WAYLAND_SHELL_INTEGRATION", QByteArray("layer-shell"));

    QGuiApplication app(argc, argv);

	DemoView view(
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

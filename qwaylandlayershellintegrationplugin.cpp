#include "qwaylandlayershellintegration_p.h"

#include <QtWaylandClient/private/qwaylandshellintegrationplugin_p.h>
#include <QtPlugin>

using namespace QtLayerShell;

class QWaylandLayerShellIntegrationPlugin :
	public QtWaylandClient::QWaylandShellIntegrationPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(
			IID QWaylandShellIntegrationFactoryInterface_iid
			FILE "layer-shell.json")

public:
	virtual QtWaylandClient::QWaylandShellIntegration *create(
			const QString &key, const QStringList &paramList) override {
		Q_UNUSED(key);
		Q_UNUSED(paramList);
		return new QWaylandLayerShellIntegration();
	}
};

Q_IMPORT_PLUGIN(QWaylandLayerShellIntegrationPlugin);

#include "qwaylandlayershellintegrationplugin.moc"

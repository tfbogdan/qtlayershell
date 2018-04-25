#include <QtLayerShell/layershellintegration_p.h>
#include <QtPlugin>
#include <QtWaylandClient/private/qwaylandshellintegrationplugin_p.h>

using namespace QtLayerShell;

class LayerShellIntegrationPlugin :
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
		return new LayerShellIntegration();
	}
};

Q_IMPORT_PLUGIN(LayerShellIntegrationPlugin);

#include "layershellintegrationplugin.moc"

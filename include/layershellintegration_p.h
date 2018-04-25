#ifndef _LAYERSHELLINTEGRATION_P_H
#define _LAYERSHELLINTEGRATION_P_H
#include <wayland-client.h>
#include <QtWaylandClient/private/qwaylandshellintegration_p.h>
#include "layershell_p.h"

namespace QtLayerShell {

class QWaylandLayerShell;

class LayerShellIntegration : public QtWaylandClient::QWaylandShellIntegration
{
public:
	LayerShellIntegration();

    bool initialize(QtWaylandClient::QWaylandDisplay *display) override;
	QtWaylandClient::QWaylandShellSurface *createShellSurface(
			QtWaylandClient::QWaylandWindow *window) override;

private:
    static void registryLayer(void *data, struct wl_registry *registry,
			uint32_t id, const QString &interface, uint32_t version);

	LayerShell *m_layerShell;
};

}

#endif

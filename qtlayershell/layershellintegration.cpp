#include "layershellintegration_p.h"
#include "layershell_p.h"
#include <qwayland-wlr-layer-shell-unstable-v1.h>
#include <QtWaylandClient/private/qwaylandwindow_p.h>
#include <QtWaylandClient/private/qwaylanddisplay_p.h>

QT_BEGIN_NAMESPACE

namespace QtLayerShell {

LayerShellIntegration::LayerShellIntegration() : m_layerShell(Q_NULLPTR)
{
}

bool LayerShellIntegration::initialize(QtWaylandClient::QWaylandDisplay *display)
{
    QWaylandShellIntegration::initialize(display);
    display->addRegistryListener(registryLayer, this);
    return m_layerShell != nullptr;
}

QtWaylandClient::QWaylandShellSurface *LayerShellIntegration::
	createShellSurface(QtWaylandClient::QWaylandWindow *window)
{
    return m_layerShell->createLayerSurface(window);
}

void LayerShellIntegration::registryLayer(void *data,
	struct wl_registry *registry, uint32_t id,
	const QString &interface, uint32_t version)
{
    LayerShellIntegration *shell = static_cast<LayerShellIntegration *>(data);

    if (interface == QStringLiteral("zwlr_layer_shell_v1")) {
        shell->m_layerShell = new LayerShell(shell->m_display,
				new QtWayland::zwlr_layer_shell_v1(registry, id, version));
	}
}

}

QT_END_NAMESPACE

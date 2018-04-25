#include "layershell_p.h"
#include "layersurface_p.h"
#include <qwayland-wlr-layer-shell-unstable-v1.h>
#include <QtWaylandClient/private/qwaylandwindow_p.h>
#include <QtWaylandClient/private/qwaylanddisplay_p.h>

namespace QtLayerShell {

LayerShell::LayerShell(QtWaylandClient::QWaylandDisplay *display,
		struct QtWayland::zwlr_layer_shell_v1 *shell) :
	QtWayland::zwlr_layer_shell_v1(shell->object()),
	m_display(display)
{
}

LayerShell::~LayerShell()
{
	zwlr_layer_shell_v1_destroy(object());
}

LayerSurface *LayerShell::createLayerSurface(
		QtWaylandClient::QWaylandWindow *window)
{
	return new LayerSurface(this, window);
}

}

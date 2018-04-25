#include "qwaylandlayershell_p.h"
#include "qwaylandlayersurface_p.h"

#include <qwayland-wlr-layer-shell-unstable-v1.h>
#include <QtWaylandClient/private/qwaylandwindow_p.h>
#include <QtWaylandClient/private/qwaylanddisplay_p.h>

namespace QtLayerShell {

QWaylandLayerShell::QWaylandLayerShell(
		QtWaylandClient::QWaylandDisplay *display,
		struct QtWayland::zwlr_layer_shell_v1 *shell) :
	QtWayland::zwlr_layer_shell_v1(shell->object()),
	m_display(display)
{
}

QWaylandLayerShell::~QWaylandLayerShell()
{
	zwlr_layer_shell_v1_destroy(object());
}

QWaylandLayerSurface *QWaylandLayerShell::createLayerSurface(
		QtWaylandClient::QWaylandWindow *window)
{
	return new QWaylandLayerSurface(this, m_display, window);
}

}

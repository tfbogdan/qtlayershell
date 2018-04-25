#ifndef _LAYERSHELL_H
#define _LAYERSHELL_H
#include <wayland-client.h>
#include <qwayland-wlr-layer-shell-unstable-v1.h>
#include <QtWaylandClient/private/qwaylandshellintegration_p.h>
#include <QtWaylandClient/private/qwaylandwindow_p.h>
#include "layersurface_p.h"

namespace QtLayerShell {

class LayerShell : public QtWayland::zwlr_layer_shell_v1
{
public:
    LayerShell(QtWaylandClient::QWaylandDisplay *display,
			struct QtWayland::zwlr_layer_shell_v1 *shell);
    virtual ~LayerShell();

	LayerSurface *createLayerSurface(QtWaylandClient::QWaylandWindow *window);
	// TODO: Popups
private:
	QtWaylandClient::QWaylandDisplay *m_display;
};

}

#endif

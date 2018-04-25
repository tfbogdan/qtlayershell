#include "qwaylandlayershell_p.h"
#include "qwaylandlayersurface_p.h"
#include "qlayerview_p.h"

#include <qwayland-wlr-layer-shell-unstable-v1.h>
#include <QtWaylandClient/private/qwaylandwindow_p.h>
#include <QtWaylandClient/private/qwaylanddisplay_p.h>

#include <iostream>
#include <stdio.h>

namespace QtLayerShell {

QtWayland::zwlr_layer_surface_v1 create_layer_surface(
		QWaylandLayerShell *shell,
		QtWaylandClient::QWaylandWindow *window)
{
	// TODO: Select the output
	fprintf(stderr, "ptr from layer surface: %p\n", window->window());
	auto layerview = dynamic_cast<LayerView*>(window->window());
	if (layerview != nullptr) {
		return shell->get_layer_surface(window->object(),
				nullptr,
				layerview->m_layer,
				layerview->m_layer_namespace);
	}
	return shell->get_layer_surface(window->object(),
			nullptr,
			QtWayland::zwlr_layer_shell_v1::layer_top,
			QString::fromUtf8("qt"));
}

QWaylandLayerSurface::QWaylandLayerSurface(
		QWaylandLayerShell *shell,
		QtWaylandClient::QWaylandDisplay *display,
		QtWaylandClient::QWaylandWindow *window) :
	QtWaylandClient::QWaylandShellSurface(window),
	QtWayland::zwlr_layer_surface_v1(create_layer_surface(shell, window)),
	m_window(window)
{
	set_size(m_window->window()->width(), m_window->window()->height());
	m_layerview = dynamic_cast<LayerView*>(window->window());
	if (m_layerview == nullptr) {
		qWarning("Warning: using LayerView is strongly recommended");
	} else {
		m_layerview->m_layer_surface = this;
		m_layerview->apply();
	}
	Q_UNUSED(display); // TODO: remove
}

QWaylandLayerSurface::~QWaylandLayerSurface()
{
    destroy();
}

void QWaylandLayerSurface::setType(Qt::WindowType type,
		QtWaylandClient::QWaylandWindow *transientParent)
{
    Q_UNUSED(type) // TODO: popups
    Q_UNUSED(transientParent)
}

void QWaylandLayerSurface::zwlr_layer_surface_v1_closed()
{
	m_window->window()->close();
}

void QWaylandLayerSurface::zwlr_layer_surface_v1_configure(uint32_t serial,
			uint32_t width, uint32_t height)
{
	m_window->configure(0, width, height);
	ack_configure(serial);
}

}

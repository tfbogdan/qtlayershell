#include "qlayerview_p.h"
#include "qwaylandlayersurface_p.h"
#include <QtWaylandClient/private/qwaylanddisplay_p.h>
#include <stdio.h>

namespace QtLayerShell {

LayerView::LayerView(uint32_t layer, const QString &layer_namespace) :
	m_layer(layer), m_layer_namespace(layer_namespace)
{
}

void LayerView::apply()
{
	if (m_layer_surface == nullptr) {
		return;
	}
	m_layer_surface->set_anchor(m_anchor);
	m_layer_surface->set_exclusive_zone(m_exclusive_zone);
	// Commit and roundtrip immediately
	m_layer_surface->m_window->QtWayland::wl_surface::commit();
	m_layer_surface->m_window->display()->forceRoundTrip();
}

void LayerView::setAnchor(uint32_t anchor)
{
	m_anchor = anchor;
	apply();
}

void LayerView::setExclusiveZone(int32_t exclusive_zone)
{
	m_exclusive_zone = exclusive_zone;
	apply();
}

}

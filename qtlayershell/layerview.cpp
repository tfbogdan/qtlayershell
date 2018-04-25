#include <QtLayerShell/layerview.h>
#include <QtLayerShell/layersurface_p.h>
#include <QtWaylandClient/private/qwaylanddisplay_p.h>

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
	m_layer_surface->set_margin(m_margin.top, m_margin.right,
			m_margin.bottom, m_margin.left);
	m_layer_surface->set_keyboard_interactivity(m_keyboard_interactivity);
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

void LayerView::setMargin(int32_t top, int32_t right,
		int32_t bottom, int32_t left) {
	m_margin.top = top;
	m_margin.right = right;
	m_margin.bottom = bottom;
	m_margin.left = left;
	apply();
}

void LayerView::setKeyboardInteractivity(bool keyboard_interactivity)
{
	m_keyboard_interactivity = keyboard_interactivity;
	apply();
}

}

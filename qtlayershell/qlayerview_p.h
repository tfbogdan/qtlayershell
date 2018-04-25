#ifndef _LAYERVIEW_P_H
#define _LAYERVIEW_P_H

#include <qwayland-wlr-layer-shell-unstable-v1.h>
#include <QtWaylandClient/private/qwaylandwindow_p.h>

#include <QString>
#include <QQuickView>
#include <stdint.h>

namespace QtLayerShell {

class QWaylandLayerSurface;
class QWaylandLayerShell;

class LayerView : public QQuickView
{
public:
	LayerView(uint32_t layer, const QString &layer_namespace);

	enum layer {
		layer_background = 0,
		layer_bottom = 1,
		layer_top = 2,
		layer_overlay = 3
	};

	enum anchor {
		anchor_top = 1, // the top edge of the anchor rectangle
		anchor_bottom = 2, // the bottom edge of the anchor rectangle
		anchor_left = 4, // the left edge of the anchor rectangle
		anchor_right = 8 // the right edge of the anchor rectangle
	};

	void setAnchor(uint32_t anchor);

	void setExclusiveZone(int32_t zone);

	void setMargin(int32_t top, int32_t right, int32_t bottom, int32_t left);

	void setKeyboardInteractivity(bool interactive);

	// TODO: popups

private:
	void apply();

	uint32_t m_layer;
	QString m_layer_namespace;

	uint32_t m_anchor = 0;
	int32_t m_exclusive_zone = 0;
	bool m_keyboard_interactivity = false;
	struct {
		int32_t top = 0, right = 0, bottom = 0, left = 0;
	} m_margin;

	QWaylandLayerSurface *m_layer_surface = NULL;

	friend class QWaylandLayerSurface;
	// haaaaack
	friend QtWayland::zwlr_layer_surface_v1 create_layer_surface(
		QWaylandLayerShell *shell,
		QtWaylandClient::QWaylandWindow *window);
};

}

#endif

TEMPLATE = app
TARGET = quickhelloworld
INCLUDEPATH += .

DEFINES += QT_DEPRECATED_WARNINGS

QT += core gui quick waylandclient waylandclient-private

CONFIG += debug link_pkgconfig wayland-scanner plugin static

QMAKE_USE += wayland-client

WAYLANDCLIENTSOURCES += \
	wlr-layer-shell-unstable-v1.xml \
	xdg-shell.xml

SOURCES += \
	main.cpp \
	qwaylandlayershellintegration.cpp \
	qwaylandlayershell.cpp \
	qwaylandlayersurface.cpp \
	qwaylandlayershellintegrationplugin.cpp \
    qlayerview.cpp

HEADERS += \
	qwaylandlayershellintegration_p.h \
	qwaylandlayershell_p.h \
	qwaylandlayersurface_p.h

RESOURCES += main.qrc

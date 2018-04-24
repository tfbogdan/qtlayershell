/***************************************************************************
 *   Copyright (C) 2018 by Eike Hein <hein@kde.org>                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include <QGuiApplication>
#include <QQuickView>
#include "qlayerview_p.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

	QtLayerShell::LayerView view(
			QtLayerShell::LayerView::layer_bottom,
			QString::fromUtf8("demo"));
	view.setAnchor(QtLayerShell::LayerView::anchor_bottom
			| QtLayerShell::LayerView::anchor_left
			| QtLayerShell::LayerView::anchor_right);
	view.setExclusiveZone(20);
	view.setMargin(0, 100, 0, 100);
	view.setKeyboardInteractivity(true);

    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/hello.qml"));
	view.setHeight(20);
    view.show();

    return app.exec();
}

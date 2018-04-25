# https://github.com/mesonbuild/meson/issues/3471
private_modules = ['QtCore', 'QtGui', 'QtWaylandClient']
private_module_includes = []
foreach module : private_modules
	private_module_includes += '/usr/include/qt/@0@/@1@'.format(
		module, qt5_modules.version())
	private_module_includes += '/usr/include/qt/@0@/@1@/@0@'.format(
		module, qt5_modules.version())
endforeach
qt_private = include_directories(private_module_includes)

# https://github.com/mesonbuild/meson/issues/3470
qtlayershell_moc_args = [
	'-I/usr/include/qt',
	'-I/usr/include/qt/QtWaylandClient/5.10.1',
	'-I/usr/include/qt/QtWaylandClient/5.10.1/QtWaylandClient',
	'-I/usr/include/qt/QtWaylandClient',
	'-I/usr/include/qt/QtCore/5.10.1',
	'-I/usr/include/qt/QtCore/5.10.1/QtCore',
	'-I/usr/include/qt/QtCore',
]

qtlayershell_moc = qt5.preprocess(
	moc_sources: [
		'qwaylandlayershellintegrationplugin.cpp',
	],
	moc_headers: [
		'qwaylandlayersurface_p.h',
	],
	moc_extra_arguments: qtlayershell_moc_args,
)

qtlayershell_inc = [include_directories('.'), qt_private]
qtlayershell_deps = [qt5_modules, wayland_client, lib_protos]

libqtlayershell = library(
	'qtlayershell', [
		'qlayerview.cpp',
		'qwaylandlayershell.cpp',
		'qwaylandlayershellintegration.cpp',
		'qwaylandlayershellintegrationplugin.cpp',
		'qwaylandlayersurface.cpp',
		qtlayershell_moc,
	],
	version: '0.0.0',
	link_whole: [protos],
	dependencies: qtlayershell_deps,
	include_directories: qtlayershell_inc,
	install: true,
)

qtlayershell = declare_dependency(
	link_with: libqtlayershell,
	dependencies: qtlayershell_deps,
	include_directories: qtlayershell_inc,
)

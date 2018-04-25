project(
	'qt-layer-shell',
	['c', 'cpp'],
	version: '0.0.1',
	license: 'MIT',
	meson_version: '>=0.44.0',
)

add_project_arguments(
	'-DQT_STATICPLUGIN',
	'-DQT_PLUGIN',
	language: 'cpp')

qt5 = import('qt5')
qt5_modules = dependency('qt5', modules: [
	'Core',
	'Gui',
	'Quick',
	'WaylandClient',
])
wayland_client = dependency('wayland-client')
wayland_protos = dependency('wayland-protocols')

subdir('protos')

# https://github.com/mesonbuild/meson/issues/3470
moc_args = [
	'-I/usr/include/qt',
	'-I/usr/include/qt/QtWaylandClient/5.10.1',
	'-I/usr/include/qt/QtWaylandClient/5.10.1/QtWaylandClient',
	'-I/usr/include/qt/QtWaylandClient',
	'-I/usr/include/qt/QtCore/5.10.1',
	'-I/usr/include/qt/QtCore/5.10.1/QtCore',
	'-I/usr/include/qt/QtCore',
]

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

moc_processed = qt5.preprocess(
	moc_sources: [
		'qwaylandlayershellintegrationplugin.cpp',
	],
	moc_headers: [
		'qwaylandlayersurface_p.h',
	],
	moc_extra_arguments: moc_args,
	qresources: 'main.qrc'
)

hello_layers = executable('hello-layers',
	sources: [
		'main.cpp',
		'qlayerview.cpp',
		'qwaylandlayershell.cpp',
		'qwaylandlayershellintegration.cpp',
		'qwaylandlayershellintegrationplugin.cpp',
		'qwaylandlayersurface.cpp',
		moc_processed
	],
	include_directories: [
		include_directories('.'),
		qt_private
	],
	dependencies: [
		qt5_modules,
		lib_protos
	]
)

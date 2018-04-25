project(
	'qtlayershell',
	['c', 'cpp'],
	version: '0.0.1',
	license: 'MIT',
	meson_version: '>=0.44.0',
)

add_project_arguments('-DQT_STATICPLUGIN', '-DQT_PLUGIN', language: 'cpp')

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
subdir('qtlayershell')

hello_resources = qt5.preprocess(
	qresources: 'main.qrc'
)

hello_layers = executable('hello-layers',
	sources: ['main.cpp', hello_resources],
	dependencies: [qtlayershell]
)

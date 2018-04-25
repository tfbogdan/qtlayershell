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

qtlayershell_inc = include_directories('include')

subdir('protos')
subdir('qtlayershell')
subdir('demo')

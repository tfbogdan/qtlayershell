wl_protocol_dir = wayland_protos.get_pkgconfig_variable('pkgdatadir')

sh = find_program('sh')
waylandscanner = find_program('wayland-scanner')
qtwaylandscanner = find_program('qtwaylandscanner')

if wayland_client.version().version_compare('>=1.14.91')
	code_type = 'private-code'
else
	code_type = 'code'
endif

wayland_scanner_code = generator(
	waylandscanner,
	output: 'wayland-@BASENAME@-protocol.c',
	arguments: [code_type, '@INPUT@', '@OUTPUT@'],
)

wayland_scanner_header = generator(
	waylandscanner,
	output: 'wayland-@BASENAME@-client-protocol.h',
	arguments: ['client-header', '@INPUT@', '@OUTPUT@'],
)

qtwayland_scanner_code = generator(
	sh,
	output: '@BASENAME@-protocol.cpp',
	arguments: [
		'-c', '@0@ client-code @INPUT@ > @OUTPUT@'.format(
			join_paths(qtwaylandscanner.path()))
	]
)

qtwayland_scanner_header = generator(
	sh,
	output: 'qwayland-@BASENAME@.h',
	arguments: [
		 '-c', '@0@ client-header @INPUT@ > @OUTPUT@'.format(
			join_paths(qtwaylandscanner.path()))
	]
)

protocols = [
	[wl_protocol_dir, 'stable/xdg-shell/xdg-shell.xml'],
	'wlr-layer-shell-unstable-v1.xml',
]

protos_src = []
protos_headers = []

foreach p : protocols
	xml = join_paths(p)
	protos_src += wayland_scanner_code.process(xml)
	protos_src += qtwayland_scanner_code.process(xml)
	protos_headers += wayland_scanner_header.process(xml)
	protos_headers += qtwayland_scanner_header.process(xml)
endforeach

protos = static_library(
	'protos',
	protos_src + protos_headers,
	dependencies: [
		wayland_client, # for the include directory
		qt5_modules,
	]
)

lib_protos = declare_dependency(
	link_with: protos,
	sources: protos_headers,
)

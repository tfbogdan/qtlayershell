hello_resources = qt5.preprocess(
	qresources: 'main.qrc'
)

hello_layers = executable('hello-layers',
	sources: ['main.cpp', hello_resources],
	dependencies: [qtlayershell]
)

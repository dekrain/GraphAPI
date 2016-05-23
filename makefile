all:
	g++ Main.cpp -shared -o Grapher.dll
test: all
	g++ GraphTestApp.cpp Grapher.dll -o GPHTEST
	./GPHTEST

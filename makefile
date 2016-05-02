all:
	g++ Main.cpp -shared -o Grapher.library
test:
	g++ GraphTestApp.cpp Grapher.library -o GPHTEST
	./GPHTEST

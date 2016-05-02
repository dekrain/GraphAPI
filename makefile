all:
	g++ Main.cpp -o Grapher.dll
test:
	g++ GraphTestApp.cpp -o GPHTEST
	./GPHTEST

FLAGS = -g -c --std=c++17

all:
		mkdir -p bin
		g++ $(FLAGS) src/envio.cpp -o bin/envio.o
		g++ $(FLAGS) src/envioFedEX.cpp -o bin/envioFedEX.o
		g++ $(FLAGS) src/envioServicioPostal.cpp -o bin/envioServicioPostal.o
		g++ $(FLAGS) src/main.cpp -o bin/main.o
		g++ -g -o bin/envios bin/envioFedEX.o bin/envioServicioPostal.o bin/main.o bin/envio.o
test:
		mkdir -p bin
		g++ $(FLAGS) tests/tests_enviofedex_calculoenvio.cpp -o bin/tests_enviofedex_calculoenvio.o
		g++ $(FLAGS) tests/tests_envioserviciopostal_calculoenvio.cpp -o bin/tests_envioserviciopostal_calculoenvio.o
		g++ $(FLAGS) src/envio.cpp -o bin/envio.o
		g++ $(FLAGS) src/envioFedEX.cpp -o bin/envioFedEX.o
		g++ $(FLAGS) src/envioServicioPostal.cpp -o bin/envioServicioPostal.o
		g++ -g -o bin/tests bin/tests_enviofedex_calculoenvio.o bin/tests_envioserviciopostal_calculoenvio.o bin/envio.o bin/envioFedEX.o bin/envioServicioPostal.o -lgtest -lgtest_main -lpthread 

clean:
		rm -Rf bin
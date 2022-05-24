FLAGS = -g -c --std=c++17

all:
		mkdir -p bin
		g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
		g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
		g++ $(FLAGS) src/empleadoIndependientePorHoras.cpp -o bin/empleadoIndependientePorHoras.o
		g++ $(FLAGS) src/planilla.cpp -o bin/planilla.o
		g++ $(FLAGS) src/main.cpp -o bin/main.o
		g++ -g -o bin/planillas bin/empleadoNomina.o bin/empleadoIndependientePorHoras.o bin/main.o bin/empleado.o bin/planilla.o
test:
		mkdir -p bin
		g++ $(FLAGS) src/empleado.cpp -o bin/empleado.o
		g++ $(FLAGS) src/empleadoNomina.cpp -o bin/empleadoNomina.o
		g++ $(FLAGS) src/empleadoIndependientePorHoras.cpp -o bin/empleadoIndependientePorHoras.o
		g++ $(FLAGS) tests/tests_empleadoindependienteporhoras_calcularpagoneto.cpp -o bin/tests_empleadoindependienteporhoras_calcularpagoneto.o
		g++ $(FLAGS) tests/tests_empleadonomina_calcularpagoneto.cpp -o bin/tests_empleadonomina_calcularpagoneto.o
		g++ $(FLAGS) tests/tests_empleado_obteneratributos.cpp -o bin/tests_empleado_obteneratributos.o
		g++ -g -o bin/tests bin/tests_empleadoindependienteporhoras_calcularpagoneto.o bin/tests_empleadonomina_calcularpagoneto.o bin/tests_empleado_obteneratributos.o  bin/empleado.o bin/empleadoIndependientePorHoras.o bin/empleadoNomina.o -lgtest -lgtest_main -lpthread
clean:
		rm -Rf bin
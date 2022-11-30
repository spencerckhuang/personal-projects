CPPFLAGS = -std=c++11 -pedantic -Wall -Wextra


main: main.o Net.o Neuron.o
	g++ $(CPPFLAGS) -o main main.o Net.o Neuron.o

main.o: main.cpp Net.h Neuron.h
	g++ $(CPPFLAGS) -c main.cpp

Net.o: Net.cpp Net.h
	g++ $(CPPFLAGS) -c Net.cpp

Neuron.o: Neuron.cpp Neuron.h
	g++ $(CPPFLAGS) -c Neuron.cpp

clean:
	rm -f *.o main
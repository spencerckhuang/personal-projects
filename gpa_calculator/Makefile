CC = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

gpa_calculator: gpa_calculator.o gpa_functions.o
	$(CC) $(CFLAGS) -o gpa_calculator gpa_calculator.o gpa_functions.o

gpa_calculator.o: gpa_calculator.cpp gpa_functions.h
	$(CC) $(CFLAGS) -c gpa_calculator.cpp 

gpa_functions.o: gpa_functions.cpp gpa_functions.h
	$(CC) $(CFLAGS) -c gpa_functions.cpp

clean:
	rm gpa_calculator *.o
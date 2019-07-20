all: fibonacci.o main.o
	g++ -o fibonacci fibonacci.o main.o

fibonacci.o: fibonacci.cpp
	g++ -c -Wall fibonacci.cpp

main.o: main.cpp
	g++ -c -Wall main.cpp

clean:
	$(RM) fibonacci

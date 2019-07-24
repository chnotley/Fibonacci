all: fibonacci.o main.o
	g++ -o fibonacci fibonacci.o main.o verylong.o

fibonacci.o: fibonacci.cpp fibonacci.h
	g++ -c -Wall fibonacci.cpp

main.o: main.cpp
	g++ -c -Wall main.cpp

verylong.o: verylong.cpp verylong.h
	g++ -c -Wall verylong.cpp

clean:
	$(RM) fibonacci
	$(RM) *.o

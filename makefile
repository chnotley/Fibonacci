all: fibonacci.o main.o verylong.o
	g++ -o fibonacci fibonacci.o main.o verylong.o

fibonacci.o: fibonacci.cpp fibonacci.h
	g++ -c -g -Wall fibonacci.cpp

main.o: main.cpp
	g++ -c -g -Wall main.cpp

verylong.o: verylong.cpp verylong.h
	g++ -c -g -Wall verylong.cpp

clean:
	$(RM) fibonacci
	$(RM) *.o

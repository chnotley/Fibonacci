all: main.cpp fibonacci.cpp
	g++ -g -Wall -o fibonacci main.cpp

clean:
	$(RM) fibonacci

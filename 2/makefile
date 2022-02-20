all: compile run

compile:
	g++ -I ./include/ -o ./lib/Point.o -c ./src/Point.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/LineQueue.o -c ./src/LineQueue.cpp
	g++ -I ./include/ -o ./lib/AVLNode.o -c ./src/AVLNode.cpp
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include/ -o ./lib/FileReader.o -c ./src/FileReader.cpp
	g++ -I ./include/ -o ./bin/Program ./lib/Point.o ./lib/Node.o ./lib/LineQueue.o ./lib/AVLNode.o ./lib/AVL.o ./lib/FileReader.o ./src/Program.cpp

run:
	./bin/Program
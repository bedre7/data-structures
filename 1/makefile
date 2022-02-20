all: compile run
compile:  
	g++ -I ./include/ -o ./lib/FileReader.o -c ./src/FileReader.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/DoublyLinkedList.o -c ./src/DoublyLinkedList.cpp
	g++ -I ./include/ -o ./bin/Program ./lib/FileReader.o ./lib/Node.o ./lib/DoublyLinkedList.o ./src/main.cpp
run: 
	./bin/Program
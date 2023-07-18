Tum: derleme calistirma

derleme: 
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/ArrayList.o -c ./src/ArrayList.cpp
	g++ -I ./include/ -o ./lib/DosyaOku.o -c ./src/DosyaOku.cpp
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/ArrayList.o ./lib/DosyaOku.o ./lib/AVL.o ./lib/Radix.o ./lib/Node.o ./src/main.cpp
 
calistirma:
	./bin/Test
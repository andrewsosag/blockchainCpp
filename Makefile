blockchain: main.o Block.o Blockchain.o sha256.o
	g++ main.o Block.o Blockchain.o sha256.o -o blockchain -lstdc++ -std=c++11 -stdlib=libc++ -x c++ 

main.o: main.cpp
	g++ -c main.cpp

Block.o: Block.cpp Block.h
	g++ -c Block.cpp

Blockchain.o: Blockchain.cpp Blockchain.h
	g++ -c Blockchain.cpp

sha256.o: sha256.cpp sha256.h
	g++ -c sha256.cpp

clean:
	rm *.o
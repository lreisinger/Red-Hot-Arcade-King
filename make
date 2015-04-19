#makefile
all: connect4

connect4: board.o computerPlayer.o humanPlayer.o player.o connect4.o
	g++ board.o computerPlayer.o humanPlayer.o player.o connect4.o -o connect4

connect4.o: connect4.cpp
	g++ -Wall -g -std=c++11 -c connect4.cpp -o connect4.o

board.o: board.cpp board.h
	g++ -Wall -g -std=c++11 -c board.cpp -o board.o

computerPlayer.o: computerPlayer.cpp computerPlayer.h
	g++ -Wall -g -std=c++11 -c computerPlayer.cpp -o computerPlayer.o

humanPlayer.o: humanPlayer.cpp humanPlayer.h
	g++ -Wall -g -std=c++11 -c humanPlayer.cpp -o humanPlayer.o

player.o: player.cpp player.h
	g++ -Wall -g -std=c++11 -c player.cpp -o player.o

clean:
	rm -f board.o computerPlayer.o humanPlayer.o player.o connect4.o

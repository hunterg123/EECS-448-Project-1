Run: main.o Client.o Player.o Boards.o Ship.o Ai.o SpecialShot.o
	g++ -std=c++11 -g -Wall main.o Client.o Player.o Boards.o Ship.o Ai.o SpecialShot.o -o Run

main.o: main.cpp Client.h
	g++ -std=c++11 -g -Wall -c main.cpp

Client.o: Client.h Client.cpp
	g++ -std=c++11 -g -Wall -c Client.cpp

Player.o: Player.h Player.cpp
	g++ -std=c++11 -g -Wall -c Player.cpp

Ai.o: Ai.h Ai.cpp
	g++ -std=c++11 -g -Wall -c Ai.cpp

Boards.o: Boards.h Boards.cpp
	g++ -std=c++11 -g -Wall -c Boards.cpp

Ship.o: Ship.h Ship.cpp
	g++ -std=c++11 -g -Wall -c Ship.cpp

SpecialShot.o: SpecialShot.h SpecialShot.cpp
	g++ -std=c++11 -g -Wall -c SpecialShot.cpp

clean:
	rm *.o Run

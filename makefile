game: player.o space.o emptyspace.o hiddenobject.o lockedroom.o painting.o darkroom.o wall.o program.o game.o menu.o inputs.o item.o
	g++ -std=c++11 player.o space.o emptyspace.o hiddenobject.o lockedroom.o painting.o darkroom.o wall.o program.o game.o menu.o inputs.o item.o -o game

player.o: player.cpp
	g++ -std=c++11 player.cpp -c

item.o: item.cpp
	g++ -std=c++11 item.cpp -c

space.o: space.cpp
	g++ -std=c++11 space.cpp -c

emptyspace.o: emptyspace.cpp
	g++ -std=c++11 emptyspace.cpp -c

hiddenobject.o: hiddenobject.cpp
	g++ -std=c++11 hiddenobject.cpp -c

lockedroom.o: lockedroom.cpp
	g++ -std=c++11 lockedroom.cpp -c

darkroom.o: darkroom.cpp
	g++ -std=c++11 darkroom.cpp -c

wall.o: wall.cpp
	g++ -std=c++11 wall.cpp -c

painting.o: painting.cpp
	g++ -std=c++11 painting.cpp -c

program.o: program.cpp
	g++ -std=c++11 program.cpp -c

game.o: game.cpp
	g++ -std=c++11 game.cpp -c

inputs.o: inputs.cpp
	g++ -std=c++11 inputs.cpp -c

menu.o: menu.cpp
	g++ -std=c++11 menu.cpp -c

clean: 
	rm *.o game

#*******************************************
#** Program Name: Project3
#** Author: Brandon Mai
#** Date: 6/10/2019
#******************************************

#Template Adapted from Makefile help from class module 

output: main.o Bonus.o Chest.o Door.o Empty.o Fake.o Game.o Medic.o Space.o Trap.o
	g++ -std=c++11 main.o Bonus.o Chest.o Door.o Empty.o Fake.o Game.o Medic.o Space.o Trap.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Bonus.o: Bonus.cpp Bonus.hpp
	g++ -std=c++11 -c Bonus.cpp

Chest.o: Chest.cpp Chest.hpp
	g++ -std=c++11 -c Chest.cpp

Door.o: Door.cpp Door.hpp
	g++ -std=c++11 -c Door.cpp

Empty.o: Empty.cpp Empty.hpp
	g++ -std=c++11 -c Empty.cpp

Fake.o: Fake.cpp Fake.hpp
	g++ -std=c++11 -c Fake.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

Medic.o: Medic.cpp Medic.hpp
	g++ -std=c++11 -c Medic.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -c Space.cpp

Trap.o: Trap.cpp Trap.hpp
	g++ -std=c++1 -c Space.cpp

target: dependencies
	action

clean:
	rm *.o output

/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include "Space.hpp"
#include "Empty.hpp"
#include "Door.hpp"
#include "Chest.hpp"
#include "Fake.hpp"
#include "Bonus.hpp"
#include "Trap.hpp"
#include "Medic.hpp"

//Controls logic and flow of events
class Game
{
    public:
        Game();
        void start();
        void menu();
        void inputVal();
        void options(Space *ptr);
        void checkKey(Space *ptr, int container[]);
        void checkBonus(Space *ptr);
        void checkTrap(Space *ptr);
        void checkMedic(Space *ptr);

    private:
        int choice;
        int turnCounter;
        int turnLimit;
        int bag;
        int gameLooper;
        int hp;
        bool key;
        bool fake;
        bool bonus;
        bool trap;
        bool heal;

};

#endif // GAME_HPP

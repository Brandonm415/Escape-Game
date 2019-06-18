/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#include "Trap.hpp"

//Constructor
Trap::Trap()
{
    roomStatus = 6;
    roomName = "You find yourself in an empty room, but something feels different.";
}

//Open function for trap room
void Trap::open()
{
    std::cout << "There is nothing to use your key on here." << std::endl;
}

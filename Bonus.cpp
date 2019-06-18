/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#include "Bonus.hpp"

//Constructor
Bonus::Bonus()
{
    roomStatus = 4;
    roomName = "You find yourself in a room with a sign that says: Bonus room!";
}

//Open function for bonus space
void Bonus::open()
{
    std::cout << "There is nothing to use your key on here." << std::endl;
}

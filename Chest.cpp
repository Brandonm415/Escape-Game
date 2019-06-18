/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#include "Chest.hpp"

//Constructor
Chest::Chest()
{
    roomStatus = 3;
    roomName = "You find yourself in a room with a chest.";
}

//Open function for chest space
void Chest::open()
{
    std::cout << "You open the chest and find a gold key!" << std::endl;
}

/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#include "Door.hpp"

//Constructor
Door::Door()
{
    roomStatus = 2;
    roomName = "You find yourself in a room with a locked door.";
}

//Open function for door space
void Door::open()
{
    std::cout << "You try to open the door with the Gold key! It works and you are free!" << std::endl;
}



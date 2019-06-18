/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#include "Space.hpp"

//Constructor
Space::Space()
{
    top = nullptr;
    bottom = nullptr;
    right = nullptr;
    left = nullptr;
}

//Function to print room name
void Space::getRoomName()
{
    std::cout << roomName << std::endl;
}



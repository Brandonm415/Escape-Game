/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#include "Empty.hpp"

//Constructor
Empty::Empty()
{
    roomStatus = 1;
    roomName = "You find yourself in a empty room.";
}

//Open function for empty space
void Empty::open()
{
    std::cout << "There is nothing for you to use your key on in this room." << std::endl;
}

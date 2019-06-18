/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#include "Fake.hpp"

//Constructor
Fake::Fake()
{
    roomName = "You find yourself in a room with a chest.";
    roomStatus = 5;
}

//Open function for fake chest room
void Fake::open()
{
    std::cout << "You open the chest and find a gray key!" << std::endl;
}

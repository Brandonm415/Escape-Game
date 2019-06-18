#include "Medic.hpp"

//Constructor
Medic::Medic()
{
    roomStatus = 7;
    roomName = "You find yourself in a room with a box of band-aids in it.";
}

//Open function for medic room
void Medic::open()
{
    std::cout << "There is nothing for you to use your key on." << std::endl;
}

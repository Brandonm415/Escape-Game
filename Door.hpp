/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#ifndef DOOR_HPP
#define DOOR_HPP
#include "Space.hpp"

//Door room
class Door: public Space
{
    public:
        Door();
        void open();

    private:
};

#endif // DOOR_HPP

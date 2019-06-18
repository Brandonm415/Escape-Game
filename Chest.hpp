/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#ifndef CHEST_HPP
#define CHEST_HPP
#include "Space.hpp"

//Chest room
class Chest: public Space
{
    public:
        Chest();
        void open();

    private:
};

#endif // CHEST_HPP

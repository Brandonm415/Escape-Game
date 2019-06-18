/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#ifndef EMPTY_HPP
#define EMPTY_HPP
#include "Space.hpp"

//Empty space room
class Empty: public Space
{
    public:
        Empty();
        void open();

    private:
};

#endif // EMPTY_HPP

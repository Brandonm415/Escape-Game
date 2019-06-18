/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#ifndef TRAP_HPP
#define TRAP_HPP
#include "Space.hpp"

//Trap room
class Trap: public Space
{
    public:
        Trap();
        void open();

    protected:

    private:
};

#endif // TRAP_HPP

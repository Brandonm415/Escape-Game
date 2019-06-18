/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#ifndef BONUS_HPP
#define BONUS_HPP
#include "Space.hpp"

//Extend turn duration room
class Bonus: public Space
{
    public:
        Bonus();
        void open();

    protected:

    private:
};

#endif // BONUS_HPP

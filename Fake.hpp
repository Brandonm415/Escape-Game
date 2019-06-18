/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#ifndef FAKE_HPP
#define FAKE_HPP
#include "Space.hpp"

//Fake chest room
class Fake: public Space
{
    public:
        Fake();
        void open();

    protected:

    private:
};

#endif // FAKE_HPP

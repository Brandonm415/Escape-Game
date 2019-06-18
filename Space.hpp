/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <iostream>
#include <string>

//Abstract class acts as parent class for other spaces
//To decipher which room is which
//roomStatus is
//1 = empty room
//2 = door room
//3 = chest room
//4 = bonus room
//5 = fake chest
//6 = trap room
//7 = Medical room
class Space
{
    public:
        Space();
        void getRoomName();
        virtual void open() = 0;

    protected:
        Space *top;
        Space *right;
        Space *left;
        Space *bottom;
        int roomStatus;
        friend class Game;
        std::string roomName;

};

#endif // SPACE_HPP

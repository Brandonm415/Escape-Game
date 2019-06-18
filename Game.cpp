/***********************************************************
** Program name: Final Project
** Author: Brandon Mai
** Date: 6/10/2019
** Description: A game where the user has to escape from
**              a maze by finding the right key and using
**              it on the locked door.
************************************************************/
#include "Game.hpp"

//Constructor
Game::Game()
{
    turnCounter = 1;
    turnLimit = 25;
    bag = 2;
    gameLooper = 0;
    key = false;
    fake = false;
    bonus = false;
    trap = false;
    heal = false;
    hp = 10;
}

//Basic input validation function
void Game::inputVal()
{
    int holder = 0;
    while(holder < 1)
    {
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid choice. Please enter a valid choice." << std::endl;
            std::cin >> choice;
        }
        else
        {
            if(choice < 1 || choice > 4)
            {
                std::cout << "That is not a valid choice. Please enter a valid choice." << std::endl;
                std::cin >> choice;
            }
            else
            {
                holder++;
            }
        }
    }
}

//Function that displays available choices to move too
void Game::options(Space *ptr)
{
    int holder = 0;
    while(holder < 1)
    {
        bool top = false;
        bool right = false;
        bool bottom = false;
        bool left = false;
        //Check for available choices
        if(ptr->top != nullptr)
        {
            std::cout << "1. Front" << std::endl;
            top = true;
        }
        if(ptr->right != nullptr)
        {
            std::cout << "2. Right" << std::endl;
            right = true;
        }
        if(ptr->bottom != nullptr)
        {
            std::cout << "3. Bottom" << std::endl;
            bottom = true;
        }
        if(ptr->left != nullptr)
        {
            std::cout << "4. Left" << std::endl;
            left = true;
        }
        std::cin >> choice;

        //input validation
        if(choice == 1 && top == false)
        {
            std::cout << "That is not an option. Choose a valid option" << std::endl;
        }
        else if(choice == 2 && right == false)
        {
            std::cout << "That is not an option. Choose a valid option" << std::endl;
        }
        else if(choice == 3 && bottom == false)
        {
            std::cout << "That is not an option. Choose a valid option" << std::endl;
        }
        else if(choice == 4 && left == false)
        {
            std::cout << "That is not an option. Choose a valid option" << std::endl;
        }
        else if(choice > 4 || choice < 1)
        {
            std::cout << "That is not an option. Choose a valid option" << std::endl;
        }

        //Ends loop if valid choice is made
        if(choice == 1 && top == true)
        {
            holder++;
        }
        else if(choice == 2 && right == true)
        {
            holder++;
        }
        else if(choice == 3 && bottom == true)
        {
            holder++;
        }
        else if(choice == 4 && left == true)
        {
            holder++;
        }
    }
}

//Checks if user has key or not while in door room
void Game::checkKey(Space *ptr, int container[])
{
    int holder = 0;
    if(ptr->roomStatus == 2)
    {
        //If have two keys
        if((container[0] == 1 || container[1] == 1) && (container[0] == 2 || container[1] == 2))
        {
            std::cout << "You have two keys in your bag. Which key do you want to use?" << std::endl;
            std::cout << "1. Gold key" << std::endl;
            std::cout << "2. Gray key" << std::endl;
            std::cin >> choice;
            while(holder < 1)
            {
                if(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "That is not a valid choice. Please enter a valid choice." << std::endl;
                    std::cin >> choice;
                }
                else if(choice < 1 || choice > 2)
                {
                    std::cout << "That is not a valid choice. Please enter a valid choice." << std::endl;
                    std::cin >> choice;
                }
                else
                {
                    if(choice == 1)
                    {
                        ptr->open();
                        holder++;
                        gameLooper++;
                    }
                    else if(choice == 2)
                    {
                        std::cout << "The Gray key doesn't work! You try the Gold one next!" << std::endl;
                        ptr->open();
                        holder++;
                        gameLooper++;
                    }
                }
            }
        }
        //If have gold key
        else if(container[0] == 1 || container[1] == 1)
        {
            ptr->open();
            holder++;
            gameLooper++;
        }
        //If have gray key
        else if(container[0] == 2 || container[1] == 2)
        {
            std::cout << "The Gray key doesn't work! Try to find the Gold key!" << std::endl;
            holder++;
        }
        else
        {
            std::cout << "You need a key to open the door." << std::endl;
            holder++;
        }
    }
}

//Checks if current room is bonus stage or not
void Game::checkBonus(Space *ptr)
{
    if(ptr->roomStatus == 4)
    {
        //If bonus unused
        if(bonus == false)
        {
            std::cout << "You get +10 turns to your turn limit!" << std::endl;
            turnLimit = turnLimit + 10;
            bonus = true;
        }
        //If already used
        else
        {
            std::cout << "You have already activated the bonus once already!" << std::endl;
        }
    }
}

//Function to check if user is in trap room and trigger trap or not
void Game::checkTrap(Space *ptr)
{
    //If trap not sprung
    if(ptr->roomStatus == 6 && trap == false)
    {
        std::cout << "Suddenly a trap activates and you are shot by an arrow! - 5 hp!" << std::endl;
        hp = hp - 5;
        trap = true;
    }
    //If trap already used
    else if(ptr->roomStatus == 6 && trap == true)
    {
        std::cout << "The trap in the room has already been sprung." << std::endl;
    }
}

//Function to check if user is in medic room and trigger heal or not
void Game::checkMedic(Space *ptr)
{
    //If full hp already
    if(ptr->roomStatus == 7 && heal == false && hp >= 10)
    {
        std::cout << "You are already full hp, so you leave the band-aids there." << std::endl;
    }
    //Use heal
    else if(ptr->roomStatus == 7 && heal == false && hp < 10)
    {
        std::cout << "You take the band-aids and use them. +5 hp!" << std::endl;
        hp = hp + 5;
        heal = true;
    }
    //If already used
    else if(ptr->roomStatus == 7 && heal == true)
    {
        std::cout << "You have already used all the band-aids in the box." << std::endl;
    }
}

//Function to show the menu
void Game::menu()
{
    int holder = 0;
    while(holder < 1)
    {
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Welcome to ESCAPE THE GAME!" << std::endl;
        std::cout << "The goal of the game is to escape by finding the right key and opening the door." << std::endl;
        std::cout << "A cheat sheet map is provided in the lab-report for testing purposes." << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Quit" << std::endl;
        std::cin >> choice;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "That is not a valid choice. Please enter a valid choice." << std::endl;
        }
        else
        {
            if(choice == 1)
            {
                start();
            }
            else if(choice == 2)
            {
                holder++;
            }
        }
    }
}

//Function that starts the game and controls the logic of the game
void Game::start()
{
    //Container to hold keys
    //Key = 1
    //Fake = 2
    int container[bag];

    //Creating new nodes to be rooms
    Space *room1 = new Bonus;
    Space *door2 = new Door;
    Space *room3 = new Trap;
    Space *room4 = new Trap;
    Space *room5 = new Empty;
    Space *room6 = new Medic;
    Space *chest7 = new Chest;
    Space *room8 = new Empty;
    Space *chest9 = new Fake;

    //Linking up all the rooms
    room1->right = door2;
    door2->left = room1;
    door2->right = room3;
    room3->left = door2;
    room1->bottom = room4;
    room4->top = room1;
    room4->right = room5;
    room5->left = room4;
    room5->top = door2;
    door2->bottom = room5;
    room5->right = room6;
    room6->left = room5;
    room6->top = room3;
    room3->bottom = room6;
    chest7->top = room4;
    room4->bottom = chest7;
    chest7->right = room8;
    room8->left = chest7;
    room8->top = room5;
    room5->bottom = room8;
    room8->right = chest9;
    chest9->left = room8;
    chest9->top = room6;
    room6->bottom = chest9;


    //Set starting user location
    Space *currentLocation = room5;

    //Reset everything for if user wants to play again
    turnCounter = 1;
    turnLimit = 25;
    bag = 2;
    gameLooper = 0;
    key = false;
    fake = false;
    bonus = false;
    trap = false;
    heal = false;
    hp = 10;

    //Start game
    //Display Menu
    std::cout << "ESCAPE!" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "You wake up and find yourself trapped inside of a strange empty room." << std::endl;
    std::cout << "There is a piece of paper in front of you. It reads:" << std::endl;
    std::cout << "There is one door that leads to your freedom, however it is locked." << std::endl;
    std::cout << "There are two chests, one of them contains the key and another contains a fake." << std::endl;
    std::cout << "Your goal is to try and find the real key to escape." << std::endl;
    std::cout << "If you fail to escape within 25 turns, the building will explode and you will die." << std::endl;
    std::cout << "There is a bonus room that will increase your turn limit by 10 if you find it." << std::endl;
    std::cout << "There are also rooms with dangerous traps." << std::endl;
    std::cout << "Good luck and try to escape." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "TURN: " << turnCounter << std::endl;
    std::cout << "HP: " << hp << std::endl;
    std::cout << "You are currently in an empty room. There is a hallway to your right, left, front, and back." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Which hallway do you choose?" << std::endl;
    std::cout << "1. Front" << std::endl;
    std::cout << "2. Right" << std::endl;
    std::cout << "3. Back" << std::endl;
    std::cout << "4. Left" << std::endl;
    std::cin >> choice;
    inputVal();
    //Loop until game is won or lost
    turnCounter++;
    while(gameLooper < 1)
    {
        //Move up
        if(choice == 1)
        {
            std::cout << "----------------------------------" << std::endl;
            std::cout << "TURN: " << turnCounter << std::endl;
            std::cout << "HP: " << hp << std::endl;
            currentLocation = currentLocation->top;
            currentLocation->getRoomName();
            //If in chest room and don't have key
            if(currentLocation->roomStatus == 3 && key == false)
            {
                //Add key to inventory
                container[0] = 1;
                key = true;
                currentLocation->open();
            }
            //If chest is already looted
            else if(currentLocation->roomStatus == 3 && key == true)
            {
                std::cout << "The chest is already looted." << std::endl;
            }
            //If in fake chest room and don't have fake
            if(currentLocation->roomStatus == 5 && fake == false)
            {
                //Add key to inventory
                container[1] = 2;
                fake = true;
                currentLocation->open();
            }
            //If chest is already looted
            else if(currentLocation->roomStatus == 5 && fake == true)
            {
                std::cout << "The chest is already looted." << std::endl;
            }
            //Functions to check if current room triggers special interactions
            checkKey(currentLocation, container);
            checkBonus(currentLocation);
            checkTrap(currentLocation);
            checkMedic(currentLocation);
            //Check if user game overed or not
            if(gameLooper < 1)
            {
                std::cout << "----------------------------------" << std::endl;
                std::cout << "Here are your available ways to go." << std::endl;
                options(currentLocation);
                turnCounter++;
            }

        }
        //Move right
        else if(choice == 2)
        {
            std::cout << "----------------------------------" << std::endl;
            std::cout << "TURN: " << turnCounter << std::endl;
            std::cout << "HP: " << hp << std::endl;
            currentLocation = currentLocation->right;
            currentLocation->getRoomName();
            //If in chest room and don't have key
            if(currentLocation->roomStatus == 3 && key == false)
            {
                container[0] = 1;
                key = true;
                std::cout << "You find a gold key inside the chest and put it in your bag." << std::endl;
            }
            else if(currentLocation->roomStatus == 3 && key == true)
            {
                std::cout << "The chest is already looted." << std::endl;
            }
            //If in fake chest room and don't have fake
            if(currentLocation->roomStatus == 5 && fake == false)
            {
                container[1] = 2;
                fake = true;
                std::cout << "You find a grey key inside the chest and put it in your bag." << std::endl;
            }
            else if(currentLocation->roomStatus == 5 && fake == true)
            {
                std::cout << "The chest is already looted." << std::endl;
            }
            checkKey(currentLocation, container);
            checkBonus(currentLocation);
            checkTrap(currentLocation);
            checkMedic(currentLocation);
            if(gameLooper < 1)
            {
                std::cout << "----------------------------------" << std::endl;
                std::cout << "Here are your available ways to go." << std::endl;
                options(currentLocation);
                turnCounter++;
            }

        }
        //Move down
        else if(choice == 3)
        {
            std::cout << "----------------------------------" << std::endl;
            std::cout << "TURN: " << turnCounter << std::endl;
            std::cout << "HP: " << hp << std::endl;
            currentLocation = currentLocation->bottom;
            currentLocation->getRoomName();
            //If in chest room and don't have key
            if(currentLocation->roomStatus == 3 && key == false)
            {
                container[0] = 1;
                key = true;
                std::cout << "You find a gold key inside the chest and put it in your bag." << std::endl;
            }
            else if(currentLocation->roomStatus == 3 && key == true)
            {
                std::cout << "The chest is already looted." << std::endl;
            }
            //If in fake chest room and don't have fake
            if(currentLocation->roomStatus == 5 && fake == false)
            {
                container[1] = 2;
                fake = true;
                std::cout << "You find a grey key inside the chest and put it in your bag." << std::endl;
            }
            else if(currentLocation->roomStatus == 5 && fake == true)
            {
                std::cout << "The chest is already looted." << std::endl;
            }
            checkKey(currentLocation, container);
            checkBonus(currentLocation);
            checkTrap(currentLocation);
            checkMedic(currentLocation);
            if(gameLooper < 1)
            {
                std::cout << "----------------------------------" << std::endl;
                std::cout << "Here are your available ways to go." << std::endl;
                options(currentLocation);
                turnCounter++;
            }
        }
        //Move left
        else if(choice == 4)
        {
            std::cout << "----------------------------------" << std::endl;
            std::cout << "TURN: " << turnCounter << std::endl;
            std::cout << "HP: " << hp << std::endl;
            currentLocation = currentLocation->left;
            currentLocation->getRoomName();
            //If in chest room and don't have key
            if(currentLocation->roomStatus == 3 && key == false)
            {
                container[0] = 1;
                key = true;
                std::cout << "You find a gold key inside the chest and put it in your bag." << std::endl;
            }
            else if(currentLocation->roomStatus == 3 && key == true)
            {
                std::cout << "The chest is already looted." << std::endl;
            }
            //If in fake chest room and don't have fake
            if(currentLocation->roomStatus == 5 && fake == false)
            {
                container[1] = 2;
                fake = true;
                std::cout << "You find a grey key inside the chest and put it in your bag." << std::endl;
            }
            else if(currentLocation->roomStatus == 5 && fake == true)
            {
                std::cout << "The chest is already looted." << std::endl;
            }
            checkKey(currentLocation, container);
            checkBonus(currentLocation);
            checkTrap(currentLocation);
            checkMedic(currentLocation);
            if(gameLooper < 1)
            {
                std::cout << "----------------------------------" << std::endl;
                std::cout << "Here are your available ways to go." << std::endl;
                options(currentLocation);
                turnCounter++;
            }
        }

        //If turns run out end game
        if(turnCounter > turnLimit)
        {
            std::cout << "Turn limit reached! You lose!" << std::endl;
            gameLooper++;
        }

        //If hp is zero end game
        if(hp <= 0)
        {
            std::cout << "Your hp reached zero and you eventually bleed out and die! You lose!" << std::endl;
            gameLooper++;
        }
    }

    //Delete linked list
    delete room1;
    delete door2;
    delete room3;
    delete room4;
    delete room5;
    delete room6;
    delete chest7;
    delete room8;
    delete chest9;
}

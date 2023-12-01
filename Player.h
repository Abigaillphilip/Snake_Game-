#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "SnakeFood.h"

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, SnakeFood* food);
        ~Player();

        void getPlayerPos(objPos &returnPos); // Upgrade this in iteration 3.
        objPosArrayList* getPlayerPosList();
        void updatePlayerDir();
        void movePlayer();

    private:
        objPosArrayList* playerPosList;
        //objPos playerPos;   // Upgrade this in iteration 3.  
        enum Dir myDir;
        char input;
        SnakeFood* food;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif
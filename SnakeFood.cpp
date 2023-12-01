#include <iostream> // Add this include for std::cout
#include "SnakeFood.h"
#include <cstdlib>
#include <ctime>


SnakeFood::SnakeFood(GameMechs* thisgmref){
    srand(time(nullptr));
    int initialX = thisgmref->getBoardSizeX() / 2;
    int initialY = thisgmref->getBoardSizeY() / 2;
    foodPos.setObjPos(initialX, initialY, 'o');
}


SnakeFood::~SnakeFood() {

}

void SnakeFood::generateFood(objPosArrayList* playerPosList) {
    srand(static_cast<unsigned int>(time(nullptr)));
    bool playerOverlap;
    do {
        foodPos.x = (rand() % 20)+1;
        foodPos.y = (rand() % 10)+1;

        // overlapping check
        playerOverlap = false;
        objPos playerPos;
        for (int i = 0; i < playerPosList->getSize(); ++i) {
            playerPosList->getElement(playerPos, i);
            if (foodPos.isPosEqual(&playerPos)) {
                playerOverlap = true;
                break;
            }
        }

    } while (playerOverlap);

    foodPos.symbol = 'o';

}



void SnakeFood::getFoodPos(objPos &returnPos) {
    returnPos = foodPos;
}
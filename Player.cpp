#include "Player.h"


Player::Player(GameMechs* thisGMRef, SnakeFood* food)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();

    // more actions to be included
    //playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*');

    objPos initialPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*');
    playerPosList->insertHead(initialPos);

    this->food = food; 
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    // returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);

    //playerPosList->getHeadElement(returnPos);


    objPos headPos;
    playerPosList->getHeadElement(headPos);

    // Assign the values to returnPos
    returnPos.setObjPos(headPos);
}

objPosArrayList* Player::getPlayerPosList()
{
    return playerPosList;
}

void Player::updatePlayerDir()
// we need to figure out how to put input we goota do this 
{
    char input = mainGameMechsRef -> getInput();

    switch (input)
    {
        case 'w':
            if (myDir != UP && myDir!= DOWN)
                myDir = UP;
            break;
        case 'a':
            if (myDir != LEFT && myDir!= RIGHT)
                myDir = LEFT;
            break;
        case 's':
            if (myDir != UP && myDir!= DOWN)
                myDir = DOWN;
            break;
        case 'd':
            if (myDir != LEFT && myDir!= RIGHT)
                myDir = RIGHT;
            break;

        default:
            break;
        
    }
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    objPos currentPos;
    playerPosList->getHeadElement(currentPos);
    objPos newPos = currentPos;

       switch (myDir) {
        case UP:
            newPos.y--;
            break;
        case DOWN:
            newPos.y++;
            break;
        case LEFT:
            newPos.x--;
            break;
        case RIGHT:
            newPos.x++;
            break;
        case STOP:
            break;
    }

    if (newPos.x < 0) newPos.x = mainGameMechsRef->getBoardSizeX() - 1;
    if (newPos.x >= mainGameMechsRef->getBoardSizeX()) newPos.x = 0;
    if (newPos.y < 0) newPos.y = mainGameMechsRef->getBoardSizeY() - 1;
    if (newPos.y >= mainGameMechsRef->getBoardSizeY()) newPos.y = 0;

    //playerPosList->insertHead(newPos); // get head
    //playerPosList->removeTail(); // take away last element

    objPos headPos;
    playerPosList->getHeadElement(headPos);
    objPos foodPos;
    food->getFoodPos(foodPos);

    for (int i = 1; i < playerPosList->getSize(); ++i) {
        objPos bodySegment;
        playerPosList->getElement(bodySegment, i);

        if (headPos.x == bodySegment.x && headPos.y == bodySegment.y) {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
            return;
        }
    }

    if (headPos.x == foodPos.x && headPos.y == foodPos.y)
    {
        playerPosList->insertHead(newPos);
        objPos blockOff;
        food->generateFood(playerPosList);
        mainGameMechsRef->incrementScore();
    }
    else
    {
        playerPosList->insertHead(newPos);
        playerPosList->removeTail();
    }

    // PPA3 Finite State Machine logic
}


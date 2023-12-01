#ifndef SNAKEFOOD_H
#define SNAKEFOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class SnakeFood {
private:
    objPos foodPos;

public:
    //SnakeFood();
    SnakeFood(GameMechs* thisgmref);
    ~SnakeFood();

    void generateFood(objPosArrayList* playerPosList);
    void getFoodPos(objPos &returnPos);
};

#endif // SNAKEFOOD_H

#include <iostream>
#include "MacUILib.h"
#include "objPos.h" // fundamental building block
#include "GameMechs.h"
#include "Player.h"
#include "SnakeFood.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;
SnakeFood* Food;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main()
{

    Initialize();


    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13);
    Food = new SnakeFood(myGM);
    myPlayer = new Player(myGM, Food);

    objPosArrayList* playerPosList = myPlayer->getPlayerPosList();
    objPos random;

    Food->generateFood(playerPosList);
}



void GetInput(void)
{
    myGM->getInput();
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);

    objPos foodPos;
    Food->getFoodPos(foodPos);

       for (int i = 0; i < myGM->getBoardSizeY(); i++)
    {
        for (int j = 0; j < myGM->getBoardSizeX(); j++)
        {
            if (i == 0 || i == myGM->getBoardSizeY() - 1 || j == 0 || j == myGM->getBoardSizeX() - 1)
            {
                printf("%c", '#');
            }
            else
            {
                objPos playerPos;
                myPlayer->getPlayerPos(playerPos);

                bool isSnakeSegment = false;
                objPosArrayList* playerPosList = myPlayer->getPlayerPosList();
                for (int k = 0; k < playerPosList->getSize(); k++)
                {
                    objPos snakeSegment;
                    playerPosList->getElement(snakeSegment, k);

                    if (snakeSegment.x == j && snakeSegment.y == i)
                    {
                        printf("%c", snakeSegment.symbol);
                        isSnakeSegment = true;
                        break;
                    }
                }

                if (!isSnakeSegment && j == foodPos.x && i == foodPos.y)
                {
                    printf("%c", foodPos.symbol);
                }
                else if (!isSnakeSegment)
                {
                    printf("%c", ' ');
                }
            }
        }
        printf("\n");
    }

    int length = ()

    printf("Your Score: %d\n", myGM->getScore());
    printf("Board Size 20 x 10\n");
    printf("Player Position: %d, %d", tempPos.x, tempPos.y);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myGM;
    delete myPlayer;
    delete Food;
    
}
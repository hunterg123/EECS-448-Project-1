#include "Ai.h"


AI::AI(int my_difficulty)
{
    difficulty = my_difficulty;
    shipNum = 0;
}

void placeShips(){

}

bool AI::Move() // Decides which kind of move to make based on difficulty setting
{
    if (difficulty == '1') easyMove();
    else if (difficulty == '2') mediumMove();
    else hardMove();
    return true;
}

void AI::easyMove()
{

}

void AI::hardMove()
{

}


void AI::mediumMove()
{

}

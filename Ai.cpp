#include "Ai.h"


AI::AI(char my_difficulty)
{
    difficulty = toupper(my_difficulty);
}

bool AI::Move() // Decides which kind of move to make based on difficulty setting
{
    if (difficulty == 'E') easyMove();
    else if (difficulty == 'M') mediumMove();
    else hardMove();
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